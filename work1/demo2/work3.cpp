#include <iostream>
#include <string.h>

using namespace std;        //指针动作缺失,记住配套操作.开始过程结果不可缺
                            //bug太多,需要从思想上改变,需要避免一些造bug的思想

size_t splitstr(const char* str, const char* splitstr, char values[][51])
{
    if(str==0||splitstr==0) return 0;

    size_t sum =0, len =strlen(splitstr);

    const char* exist = strstr(str,splitstr);

    while(exist) 
    {
        memmove(values[sum],str,exist-str);
        values[sum][exist-str] =0;

        sum++;
        str = exist +len;
        exist = strstr(str,splitstr);
    }
    
    strcpy(values[sum],str);
    //values[sum][exist-str] =0; //不可使用
    sum++;
    return sum;

}
void deletestr(char* str, const char* substr)   
{
    if(str==0||substr==0) return;

    int slen =strlen(substr);

    char* exist=strstr(str,substr);
    char *p =0;
    while(exist)
    {
        p =exist+slen;
        while(*p)
        {
            *exist = *p;
            exist++;p++;
        }
        if(*exist) *exist =0;

        exist=strstr(str,substr);
        p=0;
    }
}

bool xmlbuffer1(const char* xmlbuffer,const char* filename,char* value,const size_t ilen=0)  //自己写的,带超多bug
{
    if(xmlbuffer==0||filename==0||value==0) return false;

    char values[21][51];     //bug一:每次接受50个字符,和ilen冲突
    size_t sum = splitstr(xmlbuffer,filename,values);

    if(sum==1) return false;
    
    size_t pos =1, len =ilen+1;
    char* p = values[pos];
    char* pv = value;
    while(true)
    {
        while(true)
        {
            *value++= *p++;
            if(!(*p)) break;

            if(ilen>0)          //bug二:len =ilen+1,这样执行value++比定义的value大小多一个.
                                //原因是代码想要多容纳'>'(认为value足够大,其实不是),结果弄巧成拙,造成段错误
            {
                len--;
                if(len<=0) break;
            }
        }
        pos +=2;
        len =ilen;
        if(pos>=sum) break;
        p = values[pos];
        *value++ = ';';
    }
    *value = 0;
    deletestr(pv,"</");
    deletestr(pv,">");
    return true;
}

bool xmlbuffer(const char* xmlbuffer, const char* filename,char*value,const size_t ilen=0)
{
    if(xmlbuffer==0||value==0||filename==0) return false;

    size_t filenamelen= strlen(filename);
    char* sfilename = new char[filenamelen+3];
    char* efilename = new char[filenamelen+4];
    memset(sfilename,0,sizeof(sfilename));
    memset(efilename,0,sizeof(efilename));

    strcpy(sfilename,"<");strcpy(sfilename+1,filename);strcpy(sfilename+filenamelen+1,">");
    strcpy(efilename,"</");strcpy(efilename+2,filename);strcpy(efilename+filenamelen+2,">");

    char* start = (char*) strstr(xmlbuffer, sfilename);
    if(start==0)
    {
        delete[] sfilename;delete[] efilename; return false;
    }

    char* end = (char*) strstr(xmlbuffer,efilename);
    if(end==0)
    {
       delete[] sfilename;delete[] efilename; return false;
    }

    size_t valuelen = end -start - filenamelen - 2;

    if(valuelen <ilen||ilen ==0)
    {
        strncpy(value,start + filenamelen +2, valuelen);
        value[valuelen] = 0;
    }
    else
    {
        strncpy(value,start + filenamelen +2, ilen);
        value[ilen] = 0;
    }

    delete[] sfilename;delete[] efilename;
    return true;

}

bool xmlbuffer(const char* xmlbuff,const char* filename,char& value)
{
    char tmpvalue[2];
    if(xmlbuffer(xmlbuff,filename,tmpvalue,1))
    {
        value = tmpvalue[0];return true;
    }
    return false;
}
bool xmlbuffer(const char* xmlbuff, const char* fieldname, unsigned char& value)
{
    char tmpvalue[2];
    if(xmlbuffer(xmlbuff,fieldname,tmpvalue,1))
    {
        value = (unsigned char) tmpvalue[0]; return true;
    }
    return false;
}
bool xmlbuffer(const char* xmlbuff, const char* fieldname, int& value)
{
    char temp[21];
    if(xmlbuffer(xmlbuff,fieldname,temp,20))
    {
        value = atoi(temp); return true;
    }
    return false;
}
bool xmlbuffer(const char* xmlbuff, const char* fieldname, unsigned int& value)
{
     char temp[21];
    if(xmlbuffer(xmlbuff,fieldname,temp,20))
    {
        value = atoi(temp); return true;
    }
    return false;
}
bool xmlbuffer(const char* xmlbuff, const char* fieldname, long& value)
{
     char temp[21];
    if(xmlbuffer(xmlbuff,fieldname,temp,20))
    {
        value = atol(temp); return true;
    }
    return false;
}
bool xmlbuffer(const char* xmlbuff, const char* fieldname, unsigned long& value)
{
     char temp[21];
    if(xmlbuffer(xmlbuff,fieldname,temp,20))
    {
        value = atol(temp); return true;
    }
    return false;
}
bool xmlbuffer(const char* xmlbuff, const char* fieldname, long long& value)
{
    char temp[21];
    if(xmlbuffer(xmlbuff,fieldname,temp,20))
    {
        value = atoll(temp); return true;
    }
    return false;
}
bool xmlbuffer(const char* xmlbuff, const char* fieldname, unsigned long long& value)
{
    char temp[21];
    if(xmlbuffer(xmlbuff,fieldname,temp,20))
    {
        value = atoll(temp); return true;
    }
    return false;
}
bool xmlbuffer(const char* xmlbuff, const char* fieldname, double& value)
{
    char temp[21];
    if(xmlbuffer(xmlbuff,fieldname,temp,20))
    {
        value = atof(temp); return true;
    }
    return false;
}
bool xmlbuffer(const char* xmlbuff, const char* fieldname, bool& value)
{
    char temp[6];
    if(xmlbuffer(xmlbuff,fieldname,temp,5))
    {
       if(strcmp(temp,"1")==0||strcmp(temp,"true")==0)
        {
            value = 1;
           
        }
        else
        {
            value = 0; 
        }
         return true;
    }
    return false;
}
int main()
{
    char xml[101], filename[51],value[1000];
    memset(xml,0,sizeof(xml));
    memset(filename, 0,sizeof(filename));
    memset(value,0,sizeof(value));

    strcpy(xml,"<bh>3</bh><name>西施</name><sex>X</sex><age>18</age><yz>true</yz>");
    // strcpy(filename, "sex");
    
    // if(xmlbuffer1(xml,filename,value))
    //     cout << filename << "=" << value << endl;
    // else 
    //     cout << "不存在" << filename <<endl;

    char sex;
    xmlbuffer(xml,"sex",sex);
    cout << "sex=" << sex <<"=" <<endl;

    int bh;
     xmlbuffer(xml,"bh",bh);
    cout << "bh=" << bh <<"=" <<endl;

    bool yz;
    xmlbuffer(xml,"yz",yz);
    cout << "yz=" << yz <<"=" <<endl;
}
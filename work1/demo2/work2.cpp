#include <iostream>
#include <string.h>

using namespace std;
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

size_t splitstr1(const char* str,const char* splitstr,char values[][51])
{
    if(str==0||splitstr==0) return 0;

    size_t slen = strlen(splitstr);
    if(slen==0) return 0;

    size_t i=0;
    char* p=(char*)str;
    char* p1 = (char*)strstr(p,splitstr);
    while(true)
    {
        if(p1!=0)
        {
            strncpy(values[i++],p ,p1-p);
            p = p1 +slen;
        }
        else
        {
            strcpy(values[i++], p);
            break;
        }
        p1 = (char*)strstr(p,splitstr);
    }
    return i;
}

int main()
{
    char values[20][51];
    memset(values,0,sizeof(values));

    char str[51], split[51];
    memset(str,0,sizeof(str));
    memset(split,0,sizeof(split));

    //strcpy(str,",aa,bb,cc,dd, ,");
    strcpy(str,"");
    strcpy(split,",");

    cout << "str=" << str << "=" <<endl;
    cout << "split=" << split << "=" <<endl;

    size_t sum = splitstr(str,split,values);

    cout << "一共有" << sum << "个数据项:" <<endl;
    for(int i=0;i<sum;i++)
        cout << "\tvalues[" << i <<"]=" << values[i] << "=" <<endl;
}
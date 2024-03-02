#include <iostream>
#include <string.h>

using namespace std;

size_t splitstr(const char* str,const char* splstr,char value[][51])
{
    if(str==0||splstr==0||value==0) return 0;

    size_t slen = strlen(splstr),pos=0;

    const char* p =0;
    size_t temp=0;
    while(true)             //str,splstr,p;  slen,pos
    {
        p =strstr(str,splstr);
        if(p) 
        {      
            memmove(value[pos],str,p-str);        //p-str>=0
            value[pos][p-str] =0;

            str = p+slen;pos++;         //update str,pos
        }
        else //pos = str中spl存在的次数, p->0   //不能动p指针
        {
            temp = strlen(str);
            memmove(value[pos],str,temp+1);

            break;
        }   
    }     
    pos++;
    return pos; 

}
int main()
{
    char values[20][51];
    memset(values,0,sizeof(values));

    char str[51], split[51];
    memset(str,0,sizeof(str));
    memset(split,0,sizeof(split));

    strcpy(str,",aa,bb,cc,dd, ,");
    //strcpy(str,"");
    strcpy(split,",");

    cout << "str=" << str << "=" <<endl;
    cout << "split=" << split << "=" <<endl;

    size_t sum = splitstr(str,split,values);

    cout << "一共有" << sum << "个数据项:" <<endl;
    for(int i=0;i<sum;i++)
        cout << "\tvalues[" << i <<"]:\t=" << values[i] << "=" <<endl;
}
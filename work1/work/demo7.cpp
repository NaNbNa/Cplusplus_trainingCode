#include <iostream>
#include <string.h>

using namespace std;
char* mystrcat(char *dest,const char* src)
{
    if(dest==0||src==0) return 0;   //资源处理

    const char* ps=src;
    char* pd = dest;

    while(*pd) pd++;  //pd最终指向0
    while(*ps)          //$ps,pd
    {
        *pd =*ps;
        pd++;ps++;      //更新
    }                   //ps->0,pd->?

    *pd =0;

    //memmove(pd,src,strlen(src)+1); //pd需要指到0
    return dest;
}

char* mystrncat(char *dest,const char* src,const size_t n)
{
    if(dest==0||src==0) return 0;   //资源处理

    const char* ps=src;
    char* pd = dest;
    size_t remain =n;

    while(*pd) pd++;  //pd最终指向0

    while(*ps&&remain-->0)          //$ps,pd;remain
    {
        *pd =*ps;
        pd++;ps++;      //更新,remain--ok
    }                   //ps->0/?,pd->?/?

    *pd =0;

    //memmove

    return dest;
}
int main()
{
    char str[101]="||lmnopqrstuvwxyz!";
    char str1[101] ="abcdefghijk";
    //memset(str,0,sizeof(str));
    //memset(str1,0,sizeof(str));

    mystrcat(str1,str);
    //mystrncat(str1,str,4);

    cout << "str:\t=" << str << "=" << endl;
    cout << "str1:\t=" << str1 << "=" <<endl;
}
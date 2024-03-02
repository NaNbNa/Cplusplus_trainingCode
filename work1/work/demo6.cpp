#include <iostream>
#include <string.h>

using namespace std;

char* mystrcpy(char* dest,const char* src)
{
    if(dest==0||src==0) return 0; //处理接受的参数

    const char *ps=src;
    char* pd = dest;
    while(*ps)       //$pd,ps
    {
        *pd = *ps;   //复制
        pd++;ps++;    //更新
    }                 //ps指向空,pd指向下一个字符

    *pd = 0; 

    //memmove(dest,src,strlen(src)+1);法二
    return dest;
}

char* mystrncpy(char* dest,const char* src,const size_t n)
{
    if(dest==0||src==0) return 0; //处理接受的参数

    const char *ps=src;
    char* pd = dest;
    size_t remain = n;
    while(*ps&&remain-->0)       //$pd,ps;remain
    {
        *pd = *ps;   //复制
        pd++;ps++;   //更新,remain已更新
    }                 //ps指向空,pd指向下一个字符

    *pd = 0;        

    //法二:使用memmove
    return dest;
}

int main()
{
    char str[101]="abcdefghijklmnopqrstuvwxyz!";
    char str1[101];
    //memset(str,0,sizeof(str));
    memset(str1,0,sizeof(str));

    //mystrcpy(str1,str);
    mystrncpy(str1,str,4);
    cout << "str:\t=" << str << "=" << endl;
    cout << "str1:\t=" << str1 << "=" <<endl;
}
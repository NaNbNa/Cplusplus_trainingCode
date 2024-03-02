#include <iostream>
#include <string.h>

using namespace std;    //可以使用memcpy函数快速写成

char* mystrcat(char* dest,const char* src)
{
    while(*dest) dest++;
    while(*src)
        *dest++ = *src++;
    *dest =0;
    return dest;
}

char* mystrncat(char* dest,const char* src,const size_t n)
{
    while(*dest) dest++;
    size_t i =n;
    while(*src&&i-->0)
        *dest++ = *src++;

    *dest =0;
    return dest;
}
int main()
{
    char dest[51];
    char dest1[51];

    memset(dest,0,sizeof(dest));
    memset(dest1,0,sizeof(dest1));

    strcpy(dest,"dest= \t");
    strcpy(dest1, "dest1= \t");

    mystrcat(dest,"abcdefghijklmnopqrstuvwxyz!");
    mystrncat(dest1,"abcdefghijklmnopqrstuvwxyz!",7);

    cout << dest   <<endl;
    cout << dest1   <<endl;
}
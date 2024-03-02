#include <iostream>
#include <string.h>

using namespace std;

const char* mystrchr(const char* str,const int c)
{
    if(str==0) return 0;    //deal param

    const char* p =str;
    while(*p)       //$p,str;c
    {
        if(*p==c) break;

        p++;    //update
    }           //p->0 or p->dest,dest是目标字符

    if(!*p) return 0;   //p->0

    return p;
}

const char* mystrrchr(const char* str,const int c)
{
    if(str==0) return 0;    //deal param

    const char* p =str;
    const char*dest =0;

    while(*p)       //$p,str;c
    {
        if(*p==c) dest =p;

        p++;    //update
    }           //p->0 

    return dest;
}
int main()
{
    char str[101]="ab cde fghijklmnopqrstuvwxyz!abcdefghijklmnopqrstuvwxyz!";
    
    char ch = '!';

    cout << "str: =" << str << "=" <<endl;
    if(mystrchr(str,ch)) cout << "exist ch:=" << ch <<"=;the firsr one:\t=" << mystrchr(str,ch) <<endl;
    else cout << "don't exist ch: =" << ch <<"=" <<endl;

    if(mystrrchr(str,ch)) cout << "exist ch:=" << ch <<"=;the last one:\t=" << mystrrchr(str,ch) <<endl;
    else cout << "don't exist ch: =" << ch <<"=" <<endl;
}
#include <iostream>
#include <string.h>

using namespace std;

void deleterchr(char* str, const int cc=' ')
{
    if(str==0) return;

    char* ps= str;
    char* p = 0;

    while(*ps)      //$ps, p
    {
        if(*ps==cc&&p==0) p = ps;
        if(*ps!=cc&&p!=0) p = 0;

        ps++;       //update
    }       //ps->0

    if(p) *p=0;     //str exist cc
}

void deletelchr(char* str, const int cc=' ')
{
    if(str==0) return;

    char* ps= str;
    char* p = 0;

    while(*ps)      //$ps, p
    {
        if(*ps==cc) p = ps;
        if(*ps!=cc) break;

        ps++;       //update ps
    }       //ps->0 or ps ->?, p-> dest(目标字符)

    size_t len =strlen(str);
    if(p) memmove(str, p+1, len - (p+1 - str) +1);    //str exist cc
}

void deletestr(char* str, const char* substr=" ")
{
    if(str==0||substr==0) return;       //deal param

    size_t slen =strlen(substr);
    size_t len = strlen(str);

    char* p = 0;
    while(true)             //$str,substr,p ;len,slen
    {
        p = strstr(str,substr);

        if(p) memmove(p,p+slen, len -(p-str) -slen +1);    //str exist substr
        else break;
    }

}
int main()
{
    char str[51];
    memset (str,0,sizeof(str));

    //strcpy(str,"abcdee aaaa aa");
    //strcpy(str,"aaaaaabaaa bcdee aaa aaaa aa");
    strcpy(str,"aaxyx  y zz  aaa");
    cout << "删除前:\t=" << str << "=" <<endl;

    //deleterchr(str,'a');
    //deletelchr(str,'a');
    deletestr(str);
    cout << "删除后:\t=" << str << "=" <<endl;

    // char* ptr=0, *p =0;
    // ptr = p;
    // if(!(*ptr))
    //     cout << "null" <<endl;
}
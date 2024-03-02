#include <iostream>
#include <string.h>

using namespace std;            //尽量不要再if一些判断语句++

int mystrcmp(const char* str1, const char* str2)
{
    if(str1==0||str2==0) return -1; //deal param

    while(true)         //$str1,str2;
    {
        if(*str1==0||*str2==0) break;
        if(*str1>*str2) return 1;
        if(*str2<*str2) return -1;
        
        str1++;str2++;
    }    //str1->0 || str2->0

    if(*str1) return 1;
    if(*str2) return -1;

    return 0;
}

int mystrncmp(const char* str1, const char* str2,const size_t n)
{
    if(str1==0||str2==0||n==0) return -2; //deal param

    size_t remain=n;
    
    while(true)          //$str1,str2;remain
    {
        if(remain<=0||(*str1==0||*str2==0)) break;
        if(*str1>*str2) return 1;
        if(*str2<*str2) return -1;
        
        str1++;str2++;remain--;         //update
    }    //str1->?/0 || str2->?/0, remain==0 or remain >0

    if(remain==0) return 0; 
    if(*str1) return 1;
    if(*str2) return -1;
    
    return 0;
}
int main()
{
    char str1[51] = "abceefghijklmnopqrstuvwxyz!";
    char str2[51] = "abcdefghijklmnopqrstuvwxyz!";

    int cmp =0;

    cmp = mystrcmp(str1,str2);
    if(cmp==1) cout <<  "=" <<str1 << "=\t" <<  " > "  "\t=" <<  str2 << "=" <<endl;
    else if(cmp==-1) cout <<  "=" <<str1 << "=\t" <<  " < "  "\t=" <<  str2 << "=" <<endl;
    else if(cmp==0) cout <<  "=" << str1 << "=\t" <<  " = "  "\t=" <<  str2 << "=" <<endl;
    else cout << "can't compare this two words!" <<endl;

    cmp = mystrncmp(str1,str2,0);
    if(cmp==1) cout <<  "=" <<str1 << "=\t" <<  " > "  "\t=" <<  str2 << "=" <<endl;
    else if(cmp==-1) cout <<  "=" <<str1 << "=\t" <<  " < "  "\t=" <<  str2 << "=" <<endl;
    else if(cmp==0) cout <<  "=" << str1 << "=\t" <<  " = "  "\t=" <<  str2 << "=" <<endl;
    else cout << "can't compare this two words!" <<endl;
}
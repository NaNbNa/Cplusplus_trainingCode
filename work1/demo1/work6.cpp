#include <iostream>
#include <string.h>

using namespace std;            //空指针是可以拿来比较的,也可以拿来if判断

int mystrcmp(const char* str1,const char* str2)  //一个return
{  
    int result = 0; //默认相等
    char* ptr1 = (char*) str1, *ptr2 = (char*)str2;

    while(*ptr1||*ptr2)
    {
        if(*ptr1 > *ptr2) result = 1;
        else if(*ptr1 < *ptr2) result = -1;

        if(*ptr1++ ==*ptr2++)  continue;
        break;
    }
    
    ptr1 =nullptr; ptr2 = nullptr;
    return result;
}

int mystrcmp1(const char* str1,const char* str2)    //多个return
{  
    size_t pos=0;
    
    char* ptr1 = (char*) str1, *ptr2 = (char*)str2;

    while(true)
    {
        if(*(ptr1+pos) > *(ptr2+pos)) return 1;
        if(*(ptr1+pos) < *(ptr2+pos)) return -1;

        if((*(ptr1+pos) == 0) && (*(ptr2+pos)==0)) return 0;
        pos++;
    }
    
}

int mystrncmp(const char* str1,const char* str2,const size_t n)
{  
    size_t i= n, result= 0; //默认相等
    char* ptr1 = (char*) str1, *ptr2 = (char*)str2;

    while((*ptr1||*ptr2)&&i-->0)
    {
        if(*ptr1 > *ptr2) result = 1;
        else if(*ptr1 < *ptr2) result = -1;

        if(*ptr1++ ==*ptr2++)  continue;
        break;
    }

    ptr1 =nullptr; ptr2 = nullptr;
    return result;
}
int main()
{
    char str1[51];
    char str2[51];

    memset(str1, 0,  sizeof(str1));
    memset(str2, 0 , sizeof(str2));

    strcpy(str1,"abcdefghijklmnopqrstuvwxyz!");
    strcpy(str2,"abcdefghijklmnopqrstuvwxyz!");
    cout << "str1= " << str1 <<endl;
    cout << "str2= " << str2 <<endl;
    int cmp = mystrncmp(str1,str2,4);

    if(cmp>0)
        cout << "str1 > str2" <<endl;
    else if(cmp <0)
        cout << "str1 < str2" <<endl;
    else 
        cout << "str1==str2" <<endl;
}
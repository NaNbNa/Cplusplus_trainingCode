#include <iostream>
#include <string.h>

using namespace std;
void deletelchr(char *str, const int cc= ' ')
{
    if(str==0)  return;
    
    bool exist=false;
    char* p = str;
    while(*str==cc)
    {
            str++;
            if(!exist)
                exist =true;
    }

    if(exist) 
    {
        while(*str) *p++=*str++;
        *p= 0;
    }
}

void deletelchr1(char *str, const int cc= ' ')
{
    if(str==0)  return;
    
    char* p = str;
    while(*p==cc) p++;

    memmove(str,p,strlen(p)+1);

}
int main()
{
    char str[51];
    memset(str,0,sizeof(str));

    strcpy(str," aaaaaabaaa bcdee aaa aaaa aa");
    cout << "=" << str << "=" <<endl;

    deletelchr1(str);
    //deletelchr(str);
    
    cout << "=" << str << "=" <<endl;
}
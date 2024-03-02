#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[51];
    memset(str,0,sizeof(str));

    cout << "str=" ;cin >>str;

    char* p =str;
    int i=0;
    while(*p++)     //指针不为空,while后递增
    {
         i++;
    }
           
    cout << "str's len=" << i <<endl;
}
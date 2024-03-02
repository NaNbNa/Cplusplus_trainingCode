#include <iostream>
#include <string.h>
using namespace std;


int _isalnum(int ch);
int _isalpha(int ch);
int _isdigit(int ch);
int _islower(int ch);
int _isupper(int ch);
int tolower1(int ch);
int toupper1(int ch);

int char_to_int(char a)
{
    //char c = '0';
    if((a >= '0') && (a <= '0'+9))
        return a - '0';
    else 
        return -1;
}
int main()
{
    //char a = 'a';
    //char A = 'A';
    char zero = '0';

    bool jx= true;
    char word ='0';
    // while (jx)
    // {
    //     cout << "请输入单个字母:"; cin >> word;
    //     if(((word >= 'a') && (word <= 'a'+24)) ||
    //       ((word >= 'A') && (word <= 'A'+24)))
    //     {
    //             cout << "字母" << word <<"的下一个字母是:" << (char)(word + 1) <<endl;
    //     }
    //     else
    //     {
    //         cout << "字母" << word << "无下一个字母" <<endl;
    //     }
        
    //     cout << "是否继续(1-继续,0-停止):";cin >> jx;
    // }
    
    while (jx)
    {
        cout << "请输入单个数字:"; cin >> word;
        cout << "字母"  << word << "对应的数字是:" << char_to_int(word) <<endl;
        cout << "是否继续(1-继续,0-停止):";cin >> jx;
    }
    
}

int _isalpha(int ch)
{
    if (((ch >= 'A') && (ch <= 'Z')) ||
        ((ch >='a')  && (ch <= 'z')) 
    )
    return 1;
    else 
    return 0;
}

int _isalnum(int ch)
{
    if (((ch >= 'A') && (ch <= 'Z')) ||
        ((ch >='a')  && (ch <= 'z')) ||
        ((ch >='0')  && (ch <= '9'))
    )
    return 1;
    else 
    return 0;
}

int _isdigit(int ch)
{
    if (
        ((ch >='0')  && (ch <= '9'))
       )
    return 1;
    else 
    return 0;
}

int _islower(int ch)
{
    if (
        ((ch >='a')  && (ch <= 'z'))
       )
    return 1;
    else 
    return 0;
}

int _isupper(int ch)
{
    if (
        ((ch >='A')  && (ch <= 'Z'))
       )
    return 1;
    else 
    return 0;
}

int tolower1(int ch)
{
    if (
        ((ch >='A')  && (ch <= 'Z'))
       )
    return 'a' + ch - 'A';
    else 
    return 0;
}

int toupper1(int ch)
{
    if (
        ((ch >='a')  && (ch <= 'z'))
       )
    return 'A' + ch - 'a';
    else 
    return 0;
}
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[31];
    memset(str,0,sizeof(str));

    cout << "输入字符串:"; cin >> str;

    cout << "反转前的字符:" << str << endl;
    int len = strlen(str);

    //原地反转,不借助其它字符串
    // char* lp = str, *hp = str +len-1;
    // char temp = 0;
    // int times = len /2;
    // while(times>0)
    // {
    //     temp = *lp;
    //     *lp = *hp;
    //     *hp = temp;
    //     lp++; hp--;times --;
    // }
    // lp =nullptr; hp =nullptr;
    //cout << "反转后的字符:" << str <<endl;


    //借助其它字符串
    char str1[31];
    memset(str1, 0,sizeof(str1));

    char*ptr =str, *ptr1 = str1+len-1;
    int times = len;
    while(times >0)
    {
        *ptr1 = *ptr;
        ptr++; ptr1--; times--;
    }
    ptr=nullptr; ptr1= nullptr;
    cout << "反转后的字符:" << str1 <<endl;
    
}
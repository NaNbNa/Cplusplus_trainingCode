#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[51];
    memset(str,0,sizeof(str));

    cout << "str="; cin >> str;     

    int len =strlen(str);           //依赖输入的字符

    if(len==0)  return 0;
    
    char *p=str;

    cout  << "正序:" ;
    for(int i=0;i<len;p++,i++)      //p指向0,不是最后的字符
        cout << *p << " ";
    
    cout <<endl;


    p--;                            //减一指向字符
    cout  << "逆序:" ;
    for(int i=0;i<len;p--,i++)
        cout << *p << " ";
    cout <<endl;

    p =nullptr;                     //指针善后工作
}
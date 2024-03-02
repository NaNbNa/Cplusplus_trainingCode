#include <iostream>
#include <string.h>

using namespace std;

int for_len(const char* ch)  //for循环
{
    int counter =0;
    for(;ch[counter] != 0;counter++){}
    return counter;
}

int while_len(const char* ch)   //while循环
{   
    int counter= 0;
    while(*ch++)        
    {
        counter++;
    }
    return counter;
}

int dp_len(const char* ch)  //递归
{
    if(*ch == 0) return 0;

    return dp_len(++ch) + 1;        //dp_len(ch++) + 1; //false,不可行
}
int main()
{
    char str[31];
    memset(str, 0 ,sizeof(str));

    cout << "输入一个字符串(最多30位):" ;
    cin >> str;

    //cout << "字符str=" << str << ",长度是:" << strlen(str) <<endl;
    cout << "字符str=" << str << ",长度是:" << for_len(str) <<endl;
    cout << "字符str=" << str << ",长度是:" << while_len(str) <<endl;
    cout << "字符str=" << str << ",长度是:" << dp_len(str) <<endl;
}

// #include <iostream>

// using namespace std;        //函数分文件编写

// int min(int a, int b);
// int max(int a, int b);
// void print(int no , string str);
#include "tools.h"
#include "girls.h"

int main()
{   
    cout << "max (5,8) = " << max (5,8) << endl;
    cout << "min (5,8) = " << min (5,8) << endl;
    print(1, "你是一只傻傻鸟!");
    print(2, "你是一只傻傻鸟!");
    print(3, "你是一只傻傻鸟!");
    print(4, "你是一只傻傻鸟!");
    print(5, "你是一只傻傻鸟!");
    print(6, "你是一只傻傻鸟!");
    print(7, "你是一只傻傻鸟!");
    print(8, "你是一只傻傻鸟!");
    print(9, "你是一只傻傻鸟!");
}

// int max (int a, int b)
// {
//     return a > b ? a : b;
// }
// int min (int a, int b)
// {
//     return a < b ? a : b;`
// }

// void print (int no , string str)
// {
//     cout << "亲爱的" << no << "号: " << str << endl;
//}
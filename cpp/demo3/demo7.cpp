#include <iostream>

using namespace std;

int main()          //typedef 别名用法,一般放在头文件
{
    // typedef unsigned int unit;
    // typedef long long llong;
    // typedef unsigned long long ullong;

    // unit a = 1024;
    // llong  b = 545758;
    // ullong c = 123456789665;

    // cout << "sizeof(a) = " << sizeof(a)  << ",a = " << a <<endl;
    // cout << "sizeof(b) = " << sizeof(b)  << ",b = " << b <<endl;
    // cout << "sizeof(c) = " << sizeof(c)  << ",c = " << c <<endl;

    //兼容功能
    //vscode
    typedef short       int16_t;    //16位整数
    typedef int         int32_t;    //32位整数
    typedef long long   int64_t;    //64位整数
    //Linux
    typedef short       int16_t;
    typedef int         int32_t;
    typedef long        int64_t;


}
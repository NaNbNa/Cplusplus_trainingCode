#include <iostream>
#include <string.h>

using namespace std;    //string有12种操作,大多函数与构造函数作用类似
                        //作为容器,用的是前7种操作.作为字符,可以多使用5种操作

int main()
{
    string s1="11111111111111111";
    string s2="22222222222222222";

    cout << "s1的内容是:" << s1 <<endl;
    cout << "s2的内容是:" << s2 <<endl;
    cout << "s1动态数组的地址是:" << (void*)s1.data() <<endl;
    cout << "s2动态数组的地址是:" << (void*)s2.data() <<endl;
    s1.swap(s2);
    cout << "s1的内容是:" << s1 <<endl;
    cout << "s2的内容是:" << s2 <<endl;
    cout << "s1动态数组的地址是:" << (void*)s1.data() <<endl;
    cout << "s2动态数组的地址是:" << (void*)s2.data() <<endl;
}
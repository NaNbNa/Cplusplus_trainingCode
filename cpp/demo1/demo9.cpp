#include <iostream>

using namespace std;

int main()      //逗号连接，运算
{
    // int a= 10, b = 20;

    // cout << "a= " << a <<  endl,cout << "b= " << b <<  endl;

    int a, b;
    b = a = 2, a*2;
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
    b = (a =2, a*2);            //重点
    cout << b << endl;
}
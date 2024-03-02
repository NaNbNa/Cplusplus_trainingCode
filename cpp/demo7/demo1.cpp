#include <iostream>

using namespace std;

int main()  //引用的本质是指针常量
{
    int a = 3;
    int& ra = a; //引用,无强制转换

    cout << "a的地址是:" << &a << ", a = " <<a <<endl;
    cout << "ra的地址是:" << &ra << ", a = " <<ra <<endl;

    int b =5;
    ra =b;
    cout << "b的地址是: " << &b << ", b = "  << b <<endl;
    cout << "a的地址是:" << &a << ", a = " <<a <<endl;
    cout << "ra的地址是:" << &ra << ", a = " <<ra <<endl;
}
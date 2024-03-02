#include <iostream>

using namespace std;

int main()          //const与指针的混合使用
{
    int a = 3, b =8;
    const int* p = &a;
    a =13;
    //错误:*p =13;
    cout << "p = " << *p << ",a = " << a <<endl;

    p =&b;
    cout << "p = " << *p << ",b = " << b <<endl;

    int* const p1 =&a;
    *p1 = 13;
    //错误: p1 = &b;
    cout << "p = " << *p1 << ",a = " << a <<endl;
    
 }
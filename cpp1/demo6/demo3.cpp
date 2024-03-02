#include <iostream>
using namespace std;        //左值右值,右值引用,改变了临时变量的生存周期

class AA
{
public:
    int m_a = 9;
    AA()
    {
        cout << "AA()" <<endl;
    }
    AA(const AA& a)
    {
        cout << "AA(const AA& a)"  <<endl;
    }
};

AA getTemp()
{
    // AA a;
    // return a;
    return AA();
}

int main()
{
    // AA a = getTemp();
    // cout << a.m_a <<endl;

    int&& a =3;         //a左值
    int b =8;
    int&& c = b+5;
    //int& c1 = b+5;      //false,左值引用初始量需是左值,b+5是右值

    // int a1 =1;              //特例:常量引用
    // const int ra = a1;      //非常量左值

    // const int b =1;
    // const int& rb =b;       //常量左值

    // const int& rc =1;       //右值

    const AA&& aa = getTemp();

    a++;
    cout << "a=" << a <<endl;
    cout << "&a=" << &a <<endl;
    cout << "c=" << c <<endl;
    cout << "&c=" << &c <<endl;
    cout << "aa.m_a=" << aa.m_a <<endl;
    cout << "&aa=" << &aa <<endl;
    
 }
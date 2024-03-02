#include <iostream>
#include <string.h>

using namespace std;        //名字覆盖
class A
{
public:
    int m_a =50;
    int m_b = 50;

    void func()
    {
        cout << "调用了A的func函数" << endl;
    }
    void func(int a)
    {
        cout << "调用了A的func(int a)函数" << endl;
        cout << "a=" << a <<endl;
    }
};

class B:public A
{
public:
    int m_a =80;
    void func()
    {
        cout << "调用了B的func函数" << endl;
    }
};

class C:public B
{
public: 
    int m_a =30;
    void func()
    {
        cout << "调用了C的func函数" << endl;
    }
};
int main()
{
    // B b;
    // cout << "m_a= " << b.m_a <<endl;

    // b.func();
    //b.func(1);  

    // A a;
    // cout << "m_a= " << a.m_a <<endl;

    // a.A::func();    //  A:: 的使用,指定是使用A不存在继承时,可以省略
    // a.func(1);  

    C c;
    cout << "C::m_a=" << c.C::m_a <<endl;
    cout << "B::m_a=" << c.B::m_a <<endl;
    //cout << "B::m_a=" << B::m_a <<endl;     //false,需要加入对象c
    cout << "A::m_a=" << c.A::m_a <<endl;
    cout << "A::m_a=" << c.B::A::m_a <<endl;

    c.C::func();
    c.B::func();

    c.B::A::func();
    c.A::func();

}
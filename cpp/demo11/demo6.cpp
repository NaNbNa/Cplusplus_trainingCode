#include <iostream>
#include <string.h>

using namespace std;        //如何使用基类的多个构造函数
                            //指定特定构造函数需要初始化列表
class A
{
public:
    int m_a;
private:
    int m_b;
public:
    A():m_a(0),m_b(0)
    {
        cout << "调用了A默认构造函数A()" <<endl;
    }
    A(int a, int b):m_a(a),m_b(b)
    {
        cout << "调用了默认构造函数A(int a, int b)" <<endl;
    }
    A(const A&a):m_a(a.m_a+1),m_b(a.m_b+1)
    {
        cout << "调用了拷贝构造函数A(const A&a)" <<endl;
    }

    void showA()
    {
        cout << "m_a=" << m_a << ", m_b=" << m_b  <<endl;
    }
};

class B:public A
{
public:
    int m_c;
    B():m_c(0),A()
    {
        cout << "调用了派生类B的构造函数B()" << endl;
    }

    B(int a,int b,int c):A(a,b),m_c(c)
    {
        cout << "调用了派生类B的构造函数B(int a,int b,int c)" << endl;
    }
    B(const A&a,int c):A(a),m_c(c)  //使用A其他构造函数,需要指名用A的拷贝构造函数
    {
        cout << "调用了派生类B的拷贝构造函数B(const A&a,int c)" << endl;
    }
    void showB()
    {
        cout << "m_c=" << m_c << endl <<endl;
    }
};
int main()
{
    B b;
    b.showA();b.showB();

    B b1(1,2,3);
    b1.showA();b1.showB();

    A a(10,20);
    B b2(a,30);
    b2.showA();b2.showB();
}
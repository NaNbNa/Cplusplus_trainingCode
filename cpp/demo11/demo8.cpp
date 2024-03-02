#include <iostream>
#include <string.h>

using namespace std;        //内存模型匹配,继承的特殊关系

class A
{
public:
    int m_a=0;
private:
    int m_b=0;
public:
    void show()
    {
        cout << "A::show() m_a=" << m_a << ", m_b=" << m_b <<endl; 
    }
    void setb(int b)
    {
        m_b = b;
    }
};

class B:public A
{
public:
    int m_c=0;
    void show()
    {
        cout << "B::show() m_a=" << m_a << ", m_c=" << m_c <<endl;
    }
};
int main()
{
    // A a;
    // B b;

    // b.m_a = 10;
    // b.setb(20);
    // b.m_c = 30;

    // a.show();
    // a = b;      //派生类赋值给基类,赋值函数
    // a.show();

    // B b;
    // A *a = &b;        //指针

    // b.m_a = 10;
    // b.setb(20);
    // b.m_c = 30;
    // b.show();

    // a->m_a =11;
    // a->setb(22);
    // //a->m_c =30;   //false
    // a->show();

    B b;
    A& a = b;        //引用

    b.m_a = 10;
    b.setb(20);
    b.m_c = 30;
    b.show();

    a.m_a =11;
    a.setb(22);
    //a->m_c =30;   //false
    a.show();
}
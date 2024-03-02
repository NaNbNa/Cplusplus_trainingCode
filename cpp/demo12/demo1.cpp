#include <iostream>
#include <string.h>

using namespace std;    //基类指针(和引用)具有多种意义(形式),这就是多态
                        //多态的条件
class callComers
{
public:
    int m_bh=0;
     
    virtual void show()  //虚函数
    {
        cout << "callComers::show(): 我是" << m_bh << "号. " <<endl;
    }

    virtual void show(int a)
    {
        cout << "callComers::show(int a): 我是" << m_bh  <<endl;
    }
};
// virtual void callComers::show() //false
// {
//     cout << "callComers::show(): 我是" << m_bh << "号. " <<endl;
// }
class cgirl:public callComers
{
public:
    int m_age =0;

    void show()
    {
        cout << "cgirl::show(): 我是" << m_bh << "号, " << m_age << "岁." <<endl;
    }

    void show(int a)
    {
        cout << "cgirl::show(int a): 我是" << m_bh << "号, " << m_age << "岁." <<endl;
    }

    void func()
    {
        cout << "调用了func()函数" << endl;
    }
};

int main()
{
    // cgirl g;
    // g.m_bh = 8;
    // g.m_age = 23;
    // g.show();
    
    // callComers  *pa = &g;
    // pa->show();

    callComers a;a.m_bh =3;
    cgirl g; g.m_bh =8; g.m_age=23;

    callComers *p;
    // p = &a;p->show();   //多态--指针
    p = &g;p->show();
    p->show(5);         //对基类的函数的重定义
    p->callComers::show(5);         //抛弃重定义,使用基类的函数

    // callComers& ra = a; ra.show();  //引用
    // callComers& rg = g; rg.show();

    //p->func();
}
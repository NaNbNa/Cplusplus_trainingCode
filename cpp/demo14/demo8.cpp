#include <iostream>
#include <string.h>

using namespace std;        //非模板友元--在模板类中设置友元函数

template <class T1,class T2>
class AA
{
//friend void show();
friend void show(const AA<T1,T2>& a)    //法一:这种方法不可做到具体化,而且是只能在类内实现的友元函数
{
   cout << "x=" << a.m_x << ", y=" << a.m_y <<endl;
}
//friend void show(const AA<int,string>& a);

    T1 m_x;
    T2 m_y;
public:
    AA(const T1& x,const T2& y):m_x(x),m_y(y)
    {

    }
};

//AA<int,string> a(88,"你是一只傻傻鸟");

// void show()
// {
//    cout << "x=" << a.m_x << ", y=" << a.m_y <<endl;
// }

// void show(const AA<int,string>& a)
// {
//    cout << "x=" << a.m_x << ", y=" << a.m_y <<endl;
// }



int main()
{
    AA<int,string> a(88,"你是一只傻傻鸟");
    show(a);

    AA<char,string> a1(88,"你是一只傻傻鸟");
    show(a1);
}
#include <iostream>
#include <string.h>

using namespace std;         //非约束友元模板--理解即可,开发极少有用

template <class T1, class T2>
class AA
{
template <typename T> friend void show(T& a);   //区别在这里

    T1 m_x;
    T2 m_y;

public:
    AA(const T1& x,const T2& y):m_x(x),m_y(y)
    {

    }
};


template <typename T>   //通用版本
void show(T& a)
{
    cout << "定义的通用的show()版本" << "x=" << a.m_x << ", y=" << a.m_y <<endl;
}

template <>
void show(AA<int,string>& a)    //具体化的版本
{
    cout << "AA具体化<int,string>的show()的版本," << "x=" << a.m_x << ", y=" << a.m_y <<endl;
}


int main()
{
    AA<int,string> a(88,"我是一只小小鸟");
    show(a);

    AA<char,string> a1(89,"我是一只小小鸟1");
    show(a1);

}
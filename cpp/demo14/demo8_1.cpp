#include <iostream>
#include <string.h>

using namespace std;         //约束友元模板--这种友元函数模板最好,就是语法麻烦

template <typename T>
void show(T& a);            //类外声明友元函数模板,也是函数模板

template <class T1, class T2>
class AA
{
friend void show<> (AA<T1,T2>& a);     //重点***类内再次声明,这行代码让函数模板与类模板扯上关系***
    T1 m_x;
    T2 m_y;

public:
    AA(const T1& x,const T2& y):m_x(x),m_y(y)
    {

    }
};

template <class T1, class T2>
class BB
{
friend void show<> (BB<T1,T2>& a);     //类内再次声明,这行代码让函数模板与类模板扯上关系
    T1 m_x;
    T2 m_y;

public:
    BB(const T1& x,const T2& y):m_x(x),m_y(y)
    {

    }
};

template <typename T>   //友元函数是函数模板,需要定义:通用版本
void show(T& a)
{
    cout << "定义的通用的show()版本" << "x=" << a.m_x << ", y=" << a.m_y <<endl;
}

template <>
void show(AA<int,string>& a)    //具体化的版本
{
    cout << "AA具体化<int,string>的show()的版本," << "x=" << a.m_x << ", y=" << a.m_y <<endl;
}

template <>
void show(BB<int,string>& a)    //具体化的版本
{
    cout << "BB具体化<int,string>的show()的版本," << "x=" << a.m_x << ", y=" << a.m_y <<endl;
}

int main()
{
    AA<int,string> a(88,"我是一只小小鸟");
    show(a);

    AA<char,string> a1(89,"我是一只小小鸟1");
    show(a1);

    BB<int,string> b(88,"我是一只小小鸟");
    show(b);

    BB<char,string> b1(89,"我是一只小小鸟1");
    show(b1);

}
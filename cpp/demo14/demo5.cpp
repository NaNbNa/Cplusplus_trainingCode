#include <iostream>
#include <string.h>

using namespace std;

template <class T1,class T2>
class AA
{
public:
    T1 m_x;
    T2 m_y;

    AA(const T1 x,const T2 y):m_x(x),m_y(y)
    {
        cout << "调用了类模板的构造函数AA()"  <<endl;
    }

    void show() const;
};

template <class T1,class T2>
void AA<T1,T2>::show() const
{
    cout << "调用了类模板的show(): x=" <<  m_x  << ", y=" << m_y <<endl;
}

template <>
class AA<int,string>
{
public:
    int m_x;
    string m_y;

    AA(const int x,const string y):m_x(x),m_y(y)
    {
        cout << "完全具体化的构造函数AA()"  <<endl;
    }
    void show() const;
};


void AA<int,string>::show() const
{
    cout << "完全具体化的show(): x=" <<  m_x  << ", y=" << m_y <<endl;
}


template <class T1>
class AA<T1,string>
{
public:
    T1 m_x;
    string m_y;

    AA(const T1 x,const string y):m_x(x),m_y(y)
    {
        cout << "部分具体化的构造函数AA()"  <<endl;
    }
    void show() const;
};

template <class T1>
void AA<T1,string>::show() const
{
    cout << "部分具体化的show(): x=" <<  m_x  << ", y=" << m_y <<endl;
}

int main()
{
    AA<int,string> aa(8,"你是一只傻傻鸟1");
    aa.show();

    AA<char,string> aa1(7,"你是一只傻傻鸟2");
    aa1.show();

    AA<char,int> aa2(60,4);
    aa2.show();
}

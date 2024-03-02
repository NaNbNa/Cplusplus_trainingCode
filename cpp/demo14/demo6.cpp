#include <iostream>
#include <string.h>

using namespace std;

template <class T1, class T2>
class BB
{
public:
    T1 m_x;
    T2 m_y;

    BB(const T1 x, const T2 y):m_x(x),m_y(y)
    {
        cout << "调整了BB的构造函数" <<endl;
    }

    void func2() const
    {
        cout << "调用了func2()函数,: x=" << m_x << ", y=" << m_y <<endl;
    }
};

// class AA:public BB<int,string>   //普通类继承模板类
// {
// public:
//     int m_a;

//     AA(int a,int x,string y):BB(x,y),m_a(a)
//     {
//         cout << "调用了AA的构造函数" <<endl;
//     }

//     void func1()
//     {
//         cout << "调用了func1()函数: m_a="  << m_a <<endl;
//     } 
// };

template <class T1, class T2>      //模板类继承模板类
class AA:public BB<T1,T2>
{
public:
    int m_a;

    AA(int a,T1 x,T2 y):BB<T1,T2>(x,y),m_a(a)      //注意模板类的初始化列表用法
    {
        cout << "调用了AA的构造函数" <<endl;
    }

    void func1()
    {
        cout << "调用了func1()函数: m_a="  << m_a <<endl;
    } 
};

template <class T,class T1, class T2>      //模板类继承模板类
class CC:public BB<T1,T2>
{
public:
    T m_a;

    CC(T a,T1 x,T2 y):BB<T1,T2>(x,y),m_a(a)      //注意模板类的初始化列表用法
    {
        cout << "调用了CC的构造函数" <<endl;
    }

    void func3()
    {
        cout << "调用了func3()函数: m_a="  << m_a <<endl;
    } 
};
int main()
{
    // BB<int,string> bb(8, "你是一只傻傻鸟",3);
    // bb.func2();
    //bb.func1();

    // AA<int,string> aa(3, 8, "你是一只傻傻鸟");
    // aa.func1();
    // aa.func2();

    CC<int,int,string> cc(3, 8, "你是一只傻傻鸟");
    cc.func2();
    cc.func3();
    
}
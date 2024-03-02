#include <iostream>
#include <string.h>

using namespace std;    //类模板作为参数和返回值

template <class T1,class T2>
class AA
{
public:
    T1 m_x;
    T2 m_y;

    AA(const T1 x,const T2 y):m_x(x),m_y(y)
    {
        
    }

    void show() const
    {
        cout << "show() x=" << m_x << ", y=" << m_y <<endl;
    }
};

class BB
{
public:
 void show() const
 {
    cout << "调用了BB类的func() " <<endl;
 }
};

class CC
{
public:
    void operator()()           //重载()运算符
    {
        cout << "调用了CC类的仿函数" <<endl;
    }
};

AA<int,string> func(AA<int,string>& aa)      //方式一
{
    aa.show();
    cout << "调用了func(AA<int,string>& aa) " <<endl;
    return aa;
}

template <typename T1, typename T2>
AA<T1,T2> func(AA<T1,T2>& aa)                //方式二,不规范的写法
{
    aa.show();
    cout << "调用了func(AA<T1,T2>& aa)" <<endl;
    return aa;
}

// template <typename T>
// T func(T& aa)                               //方式三
// {
//     aa.show();
//     cout << "调用了func(T& aa)" <<endl;
//     return aa;
// }


template <typename T>   
void func(T& tt)
{
    tt();
    cout << "调用了func(T& tt)" <<endl;
}

void show()
{
    cout << "调用了show()普通函数" <<endl;
}
int main()
{
    AA<int,string> aa(3,"你是一只傻傻鸟");  //方式一
    auto bb = func(aa);

    AA<char,string> aa1(88,"你是一只傻傻鸟1");  //方式二
    auto bb1 = func(aa1);

    //BB b;                                   //方式三
    //auto bb2 = func(b);

    CC c;
    func(c);
    func(show);
}
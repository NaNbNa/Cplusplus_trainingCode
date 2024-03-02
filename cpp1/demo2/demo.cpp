#include <iostream>
using namespace std;

class AA
{
public:
    string m_name;

    AA()
    {
        cout << "默认构造函数AA()" <<endl;
    }

    AA(const string& name):m_name(name)
    {
        cout << "构造函数/转换函数" << ", name=" << m_name <<endl;
    }

    AA(const AA& a):m_name(a.m_name)
    {
       cout << "拷贝构造函数" << ", name=" << m_name <<endl;
    }

    AA& operator=(const AA& a)
    {
        m_name = a.m_name;
        cout << "赋值函数, name=" << m_name <<endl;
        return *this;
    }

    ~AA()
    {
        cout << "析构函数, name=" << m_name <<endl;
    }
};

// int& func()
// {
//     return (int(3));
// }

int main()
{
    // string str ="西施";
    // AA a= str;
    // //a = "西施";

    // cout << a.m_name <<endl;
    // //AA aa =a;

    // const string& name = "西施1";
    // cout << name <<endl;
}
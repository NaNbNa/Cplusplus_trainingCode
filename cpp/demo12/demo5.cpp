#include <iostream>
#include <string.h>

using namespace std;        //纯虚函数--纯虚析构函数的用法和用处

class AA
{
public: 
    AA()
    {
        cout << "调用了基类的构造函数AA()" <<endl;
    }
    virtual void func()=0;
    
    // virtual ~AA() = 0
    // { 
    //     cout << "调用了基类的析构函数~AA()。\n"; 
    // }
    virtual ~AA()=0;      
    // virtual ~AA()
    // {
    //     cout << "调用了基类的析构函数~AA()。\n";
    // }
    //virtual ~AA(){cout << "调用了基类的析构函数~AA()。\n"; };
};

AA::~AA()       //纯虚析构函数需要实现定义,但需要与声明分开定义
{
    cout << "调用了基类的析构函数~AA()。\n";
}

class BB:public AA
{
public:
    BB()
    {
        cout << "调用了派生类的构造函数BB()" <<endl;
    }
    void func()
    {
        cout << "调用了派生类的func()" <<endl;
    }
    ~BB()
    {
        cout << "调用了派生类的析构函数~BB()" <<endl;
    }
};

int main()
{
    //AA a;
    BB b;
    AA* p =&b;
    p->func();
}
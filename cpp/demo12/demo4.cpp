#include <iostream>
#include <string.h>

using namespace std;

class AA
{
public: 
    AA()
    {
        cout << "调用了基类的构造函数AA()" <<endl;
    }
    virtual void func()
    {
        cout << "调用了基类的func()" <<endl;
    }
    // virtual ~AA()           //对析构函数使用虚函数
    // {
    //     cout << "调用了基类的析构函数~AA()" <<endl;
    // }
    virtual ~AA(){};
};
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
    // AA a;
    // a.func();

    // BB b;
    // b.func();

    //BB *b = new BB;
    //b->~BB();
    //delete b;

    AA* a= new BB;
    delete a;       //不可调用派生类的成员函数
                    //当基类析构未自定义时,将会无法调用派生类的析构函数
    a = nullptr;
}
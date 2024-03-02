#include <iostream>
#include <string.h>

using namespace std;

class AA
{
public:
    AA()
    {
        cout << "调用了AA的构造函数AA()" <<endl;
    }
    AA(int a)
    {
        cout << "调用了AA的构造函数AA(int a)" <<endl;
    }
};

class BB
{
public:
    BB()
    {
        cout << "调用了BB的构造函数BB()" <<endl;
    }
    BB(int a)
    {
        cout << "调用了BB的构造函数BB(int a)" <<endl;
    }
};

class CC
{
public:
    CC()
    {
        cout << "调用了CC的构造函数CC()" <<endl;
    }
    CC(int a)
    {
        cout << "调用了CCBB的构造函数CC(int a)" <<endl;
    }
};

template <class T>
class DD
{
public:
   DD()
   {
        cout << "调用了DD的构造函数DD()" <<endl;
   } 
   DD(int a)
   {
        cout << "调用了DD的构造函数DD(int a)" <<endl;
   }
};

template <class T>      //重点
class EE:public T       //T作为基类,可以构造函数
{
public:
    EE():T()
    {
        cout << "调用了EE的构造函数EE()" <<endl;
    }
    EE(int a):T(a)
    {
        cout << "调用了EE的构造函数EE(int a)" <<endl;
    }
};

int main()
{
    EE<AA> ea1;
    EE<BB> eb1;
    EE<CC> ec1;
    EE<DD<int>> ed1;
    //EE<DD> //false
}
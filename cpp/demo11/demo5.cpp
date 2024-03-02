#include <iostream>
#include<string.h>

using namespace std;        //继承的对象模型

class A
{
public:
    int m_a =10;
protected:
    int m_b = 20;
private:
    int m_c = 30;
public:
    A()
    {
        cout << "调用了A()的构造函数" << endl;
        cout << "A中this指针指向的地址是:" << this <<endl;
        cout << "A中m_a的地址是:" << &m_a <<endl;
        cout << "A中m_b的地址是:" << &m_b <<endl;
        cout << "A中m_c的地址是:" << &m_c <<endl;
    }
    ~A()
    {
        cout << "调用了~A()的析构函数" << endl;

    }
    void func()
    {
        cout << "m_a=" << m_a << ", m_b=" << m_b << ", m_c=" << m_c <<endl;
    }
};

class B:public A
{
public:
    int m_d =40;
    B()
    {
        cout << "调用了B()的构造函数" << endl;
        cout << "B中this指针指向的地址是:" << this <<endl;
        cout << "B中m_a的地址是:" << &m_a <<endl;
        cout << "B中m_b的地址是:" << &m_b <<endl;
        cout << "B中m_d的地址是:" << &m_d <<endl;
    }
    ~B()
    {
        cout << "调用了~B()的析构函数" << endl;
    }
    void func1()
    {
        cout << "m_d=" << m_d <<endl;
    }
};
// class C:public B
// {
// public:
//     C()
//     {
//         cout << "调用了C()的构造函数" << endl;
//     }
//     ~C()
//     {
//         cout << "调用了~C()的析构函数" << endl;
//     }
// };
void* operator new(size_t size)
{
    void* ptr = malloc(size);
    cout << "申请到的内存的地址是:" << ptr <<", 大小是:" << size <<endl;
    return ptr;
}

void operator delete(void* ptr)
{
    if(ptr==0) return;
    free(ptr);
    cout << "释放内存" <<endl;
}

int main()
{
    //A a;
    //B b;
    //C c;
    cout << "基类占用内存的大小是:\t" << sizeof(A) <<endl;
    cout << "派生类占用内存的大小是:\t" << sizeof(B) <<endl;

    B* p = new B;   //只申请一次内存
    p->func();p->func1();
    //memset(p,0,sizeof(B));      //对内存进行处理,突破private语法的限制
    *((int*)p+2) =31;       //*((int*)p+2)指向私有成员m_c的内存
    p->func();p->func1();
    delete p;
}
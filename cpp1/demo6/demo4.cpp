#include <iostream>
#include <string.h>

using namespace std;    //移动语义,移动拷贝构造函数,移动赋值函数,基础类型不建议移动

class AA
{
public:
    int* m_data =nullptr;

    AA() = default;
    
    void alloc()
    {
        m_data = new int;
        memset(m_data,0,sizeof(int));
    }

    AA(const AA& a)
    {
        cout << "AA(const AA& a)" <<endl;
        if(m_data==nullptr) alloc();

        if(a.m_data==nullptr) return;
        memcpy(m_data,a.m_data,sizeof(int));
    }

    // AA(AA&& a)  //移动拷贝构造函数
    // {
    //     cout << "AA(const AA&& a)" <<endl;
    //     if(m_data!=nullptr) delete m_data;
    //     m_data = a.m_data;
    //     a.m_data = nullptr;
    // }

    AA& operator=(const AA& a)
    {
        cout << "AA& operator=(const AA& a)" <<endl;
        if(this==&a) return *this;
        if(m_data==nullptr) alloc();

        if(a.m_data==nullptr) return *this;
        memcpy(m_data,a.m_data,sizeof(int));
        return *this;
    }

    // AA& operator=(AA&& a)        //移动赋值函数
    // {
    //     cout << "AA& operator=(AA&& a)" <<endl;
    //     if(this==&a) return *this;

    //     if(m_data!=nullptr) delete m_data;
    //     m_data = a.m_data;
    //     a.m_data = nullptr;

    //     return *this;
    // }

    ~AA()
    {
        if(m_data!=nullptr)
       { delete m_data;
        m_data = nullptr;}
    }
};

int main()
{
    AA a1;
    a1.alloc();
    *a1.m_data = 3;
    cout << "a1.m_data=" << *a1.m_data <<endl;

    AA a2 = a1;
    cout << "a2.m_data=" << *a2.m_data << endl;

    AA a3;
    a3 = a1;
    cout << "a3.m_data=" << *a3.m_data << endl;

    auto f = []{
        AA aa;
        aa.alloc();
        *aa.m_data = 8;
        return aa;
    };
    AA a4 = f();
    cout << "a4.m_data=" << *a4.m_data << endl;

    AA a6;
    a6 = f();
    cout << "a6.m_data=" << *a6.m_data << endl;
}
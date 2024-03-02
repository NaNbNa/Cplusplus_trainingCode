#include <iostream>
#include <string.h>

using namespace std;        //new和delete是静态函数(就算没声明static)

class cgirl
{
public:
    int m_bh;
    int m_xw;

    cgirl(){};
    cgirl(int bh,int xw)
    {
        m_bh = bh;m_xw=xw;
        cout << "use cgirl(int bh,int xw)" <<endl;
    }
    ~cgirl()
    {
        cout << "use ~cgirl()" <<endl;
    }

    void* operator new(size_t size)
    {
        cout << "use 类void* operator new(size_t size)!" <<endl;
        void* ptr = malloc(size);
        cout << "the malloc address is:" << ptr <<endl;
        return ptr;
    }

    void operator delete(void* ptr)
    {
        cout << "use 类void oprerator delete(void* ptr)" <<endl;
        if(ptr==0) return;
        free(ptr);
    }
};  

void* operator new(size_t size)
{
    cout << "use 全局void* operator new(size_t size)!" <<endl;
    void* ptr = malloc(size);
    cout << "the malloc address is:" << ptr <<endl;
    return ptr;
}

void operator delete(void* ptr)
{
    cout << "use 全局void oprerator delete(void* ptr)" <<endl;
    if(ptr==0) return;
    free(ptr);
}

int main()
{
    int* p1 = new int(3);
    cout << "p1=" << (void*)p1 << ", *p1=" << *p1 <<endl;
    delete p1;

    cgirl* p2 = new cgirl(3,8);
    cout << "p2 address:" << p2 << ", bh=" << p2->m_bh << ", xw=" << p2->m_xw <<endl;
    delete p2;
}
#include <iostream>
#include <string.h>

using namespace std;        //简单的内存池

class cgirl
{
public:
    int m_bh;
    int m_xw;
    static char* m_pool;

    static bool initpool()
    {
        m_pool = (char*)malloc(18);
        if(m_pool==0) return false;
        memset(m_pool,0,18);
        cout << "pool的起始地址是: " << (void*)m_pool <<endl;
        return true;
    }

    static void freepool()
    {
        cout << "调用了freepool" << endl;
        if(m_pool==0) return;
        free(m_pool);
    }
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
        if(m_pool[0]==0)
        {
        cout << "分配了第一块内存" << (void*)(m_pool+1) << endl;
        m_pool[0] =1;
        return m_pool+1;
        }
        if(m_pool[9]==0)
        {
        cout << "分配了第二块内存" << (void*)(m_pool+10) << endl;
        m_pool[9] =1;
        return m_pool+10;
        }

        void* ptr = malloc(size);
        cout << "申请到的内存地址是:" << ptr <<endl;
        return ptr;
    }

    void operator delete(void* ptr)
    {
        if(ptr==0) return;

        if(ptr==m_pool+1) 
        {
            cout << "释放第一块内存!" <<endl;
            m_pool[0] =0;
            return;
        }
        if(ptr==m_pool+10) 
        {
            cout << "释放第二块内存!" <<endl;
            m_pool[9] =0;
            return;
        }

        free(ptr);

    }
};  

char* cgirl::m_pool=0;

int main()
{
    if(cgirl::initpool()==false)
    {
        cout << "分配内存池失败!" <<endl;
        return -1;
    }

    cgirl* p1 = new cgirl(1,2);
    cout << "p1 address:" << p1 << ", bh=" << p1->m_bh << ", xw=" << p1->m_xw <<endl;
    

    cgirl* p2 = new cgirl(3,4);
    cout << "p2 address:" << p2 << ", bh=" << p2->m_bh << ", xw=" << p2->m_xw <<endl;
    

    cgirl* p3 = new cgirl(5,6);
    cout << "p3 address:" << p3 << ", bh=" << p3->m_bh << ", xw=" << p3->m_xw <<endl;
    
    delete p1;

    cgirl* p4 = new cgirl(3,8);
    cout << "p4 address:" << p4 << ", bh=" << p4->m_bh << ", xw=" << p4->m_xw <<endl;

    delete p2;
    delete p3;
    delete p4;

    cgirl::freepool();
}
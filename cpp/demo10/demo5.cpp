#include <iostream>
#include <string.h>

using namespace std;

class cgirl
{
public:
    int m_bh;
    string m_name;
    int* m_ptr;

    cgirl()
    {
        m_ptr=nullptr;
    }
    ~cgirl()
    {
        delete m_ptr;
    }

    void show()
    {
        cout << "bh=" << m_bh << ",name:" << m_name <<", m_ptr=" << m_ptr 
        <<endl;
    }

    cgirl& operator=(const cgirl& g)
    {
        if(this==&g) return *this;

        if(g.m_ptr==nullptr)
        {
            if(m_ptr!=nullptr)
           { delete m_ptr;
            m_ptr=nullptr;}
        }
        else
        {
            if(m_ptr ==nullptr)
            m_ptr= new int;
            memcpy(m_ptr,g.m_ptr,sizeof(int));
        }
        m_bh = g.m_bh;m_name=g.m_name;
        cout << "use cgirl& operator=(const cgirl& g)!" <<endl;
        return *this;
    }
};
int main()
{
    cgirl g1,g2;
    g1.m_bh = 8;g1.m_name= "西施";g1.m_ptr= new int(3);
    g1.show();
    g2.show();

    g2 = g1;    //赋值函数,而不是拷贝构造函数
    g1 = g1;    //合法
    g2.show();
    cout << "g1.m_ptr=" << g1.m_ptr << ", g2.m_ptr=" << g2.m_ptr <<endl;
    cout << "*g1.m_ptr=" << *g1.m_ptr << ", *g2.m_ptr=" << *g2.m_ptr <<endl;
}
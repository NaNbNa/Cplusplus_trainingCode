#include <iostream>
#include <string.h>

using namespace std;

class cgirl
{
    public:
        string m_name;
        int m_age;
        int* m_ptr;
        cgirl()
        {
           initdata();
            cout << "调用了构造函数!" <<endl;
        }

        cgirl(const cgirl& g)
        {
            
            m_name = g.m_name;m_age = g.m_age-1;
            m_ptr = new int;
            //*m_ptr=*g.m_ptr;
            memcpy(m_ptr,g.m_ptr,sizeof(int));
            cout << "调用了拷贝构造函数!" <<endl;
        }

        ~cgirl()
        {
            delete m_ptr; m_ptr =nullptr;
            cout << "调用了析构函数!" <<endl;
        }
        
    
        void initdata()
        {
             m_name.clear();m_age = 0;m_ptr = nullptr;
        }

        void show()
        {
            cout << "姓名: " << m_name << "; 年龄: " << m_age << "; m_ptr=" 
            << m_ptr << "; *m_ptr=" << *m_ptr <<endl;
        }
};

cgirl func()
{
    cgirl gg;
    gg.m_name = "西施";gg.m_age=22;
    cout << "gg's address: " << &gg <<endl; 
    return gg;
}

int main()
{
    // cgirl girl = cgirl();

    // cout << "-------------" <<endl;

    // cgirl girl1;
    // girl1 = cgirl();
    
    // cgirl* girl = new cgirl();
    // girl->show();
    // delete girl;

    
    // g1.m_name = "西施";g1.m_age=18;
    // cgirl g1 =func();
    // cout << "g1's address: " << &g1 <<endl; 
    // g1.show();
    //cgirl g2(girl);
    // cgirl g2 = girl;
    // g2.show();

    cgirl g1;
    g1.m_name = "西施";g1.m_age=23;g1.m_ptr = new int(3);
    g1.show();
    cgirl g2(g1); *g2.m_ptr = 8;
    g1.show();
    g2.show();
}
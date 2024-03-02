#include <iostream>
#include <string.h>

using namespace std;
class cboy
{
    public:
        string m_xm;
    // cboy()
    // {
    //     m_xm.clear();
    //     cout << "调用了cboy()构造函数!" <<endl;
    // }
    cboy(string xm)
    {
        m_xm =xm;
        cout << "调用了cboy(string xm)构造函数!" <<endl;
    }
    cboy(const cboy & b)
    {
        m_xm=b.m_xm;
        cout << "调用了cboy(const cboy & b)拷贝构造函数!" <<endl;
    }
};
class cgirl
{
    public:
        string m_name;
        int m_age;
        cboy m_boy;

        // cgirl()
        // {
        //     cout << "调用了cgirl()构造函数!" <<endl;
        // }

        // cgirl(string name,int age, cboy& b)
        // {
        //     m_name = name;m_age = age;
        //     m_boy.m_xm = b.m_xm;
        //     cout << "调用了cgirl(string name,int age, cboy b)构造函数!" <<endl;
        // }

        cgirl(string name,int age, cboy& b):m_name(name),m_age(age-1),m_boy(b)
        {
            //m_boy.m_xm = b.m_xm;
            cout << "调用了cgirl(string name,int age, cboy b)构造函数!" <<endl;
        }

        // cgirl(const cgirl& g)
        // {
            
        //     m_name = g.m_name;m_age = g.m_age;
          
        //     cout << "调用了拷贝构造函数!" <<endl;
        // }

        ~cgirl()
        {
           
            cout << "调用了析构函数!" <<endl;
        }
        
    

        void show()
        {
            cout << "姓名: " << m_name << "; 年龄: " << m_age  
            << ", 男朋友:" << m_boy.m_xm <<endl;
        }
};

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

    cboy b("子都");
    cgirl g1("西施",18,b);
    //g1.m_name = "西施 ";g1.m_age=23;
    g1.show();

    
}
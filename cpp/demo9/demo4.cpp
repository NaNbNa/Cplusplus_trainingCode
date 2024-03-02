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
        mutable string m_name;
        int m_age;

        // cgirl()
        // {
        //     cout << "调用了cgirl()构造函数!" <<endl;
        // }
        cgirl(string name,int age)
        {
            m_name=name,m_age=age;
            //m_boy.m_xm = b.m_xm;
            cout << "调用了cgirl(string name,int age)构造函数!" <<endl;
        }

        void show() const
        {
            //m_age=3;
            m_name ="冰冰";
            cout << "姓名: " << m_name << "; 年龄: " << m_age  
            <<endl;
            //show();
        }

        void show1() const
        {
            //m_age=3;
            m_name ="冰冰1";
            cout << "姓名: " << m_name << "; 年龄: " << m_age  
            <<endl;
        }

        void show2() 
        {
            //m_age=3;
            m_name ="冰冰2";
            cout << "姓名: " << m_name << "; 年龄: " << m_age  
            <<endl;
            show3();
            show1();
        }

        void show3() 
        {
            //m_age=3;
            m_name ="冰冰3";
            cout << "姓名: " << m_name << "; 年龄: " << m_age  
            <<endl;
        }
};

int main()
{
    //cboy b("子都");
    // cgirl g1("西施",18);
    //g1.m_name = "西施 ";g1.m_age=23;
    // g1.show2();

    const cgirl g1("西施",18);
    g1.show();

}
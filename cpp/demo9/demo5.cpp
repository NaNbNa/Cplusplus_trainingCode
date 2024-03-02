#include <iostream>
#include <string.h>

using namespace std;        //const的妙用

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
        int m_yz;

        // cgirl()
        // {
        //     cout << "调用了cgirl()构造函数!" <<endl;
        // }
        cgirl(string name,int yz)
        {
            m_name=name, m_yz =yz;
            //m_boy.m_xm = b.m_xm;
            cout << "调用了cgirl(string name,int age)构造函数!" <<endl;
        }

        void show() const
        {
            //m_age=3;
            //m_name ="冰冰";
            cout << "姓名: " << m_name << ",是最漂亮的! " 
            <<endl;
         
        }

        const cgirl& pk(const cgirl& g1) const
        {
            if(m_yz < g1.m_yz) return *this;
            return g1;
        }
};

int main()
{
    //cboy b("子都");
    // cgirl g1("西施",18);
    //g1.m_name = "西施 ";g1.m_age=23;
    // g1.show2();

    cgirl g1("西施",5), g2("西瓜", 2), g3("冰冰", 3), g4("金莲", 4);
    const cgirl& temp = g1.pk(g2).pk(g3).pk(g4);
    
    temp.show();

}
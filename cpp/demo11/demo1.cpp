#include <iostream>
#include <string.h>

using namespace std;
// class mystring
// {
//     public:
//         char* ptr;
// };
// int main()
// {   
//     string s1 = "你是一直傻傻鸟" ;
//     mystring s2 =  "你是一直傻傻鸟";  //false
// }

class cgirl
{
public:
    int m_bh;
    string m_name;
    double m_weight;

    cgirl()
    {
        m_bh=0;m_name.clear();m_weight = 0;
        cout << "调用了cgirl()" << endl;
    }

    // cgirl(int bh)       //还是自动转换函数
    // {
    //     m_bh=bh;m_name.clear();m_weight = 0;
    //     cout << "调用了cgirl(int bh)" << endl;
    // }
    explicit cgirl(int bh)       //禁止自动转换
    {
        m_bh=bh;m_name.clear();m_weight = 0;
        cout << "调用了cgirl(int bh)" << endl;
    }
    cgirl(double weight)       //还是转换函数
    {
        m_bh=0;m_name.clear();m_weight = weight;
        cout << "调用了cgirl(double weight)" << endl;
    }
    void show()
    {
        cout << "bh=" << m_bh << ",name=" << m_name << " , weight=" << m_weight <<endl;

    }
};

void func(cgirl& g)
{
     cout << "调用了void func(cgirl g)" << endl;
}

void func(cgirl g)
{
   
    cout << "调用了void func(cgirl g)" << endl;
    g.show();
}

cgirl func1()
{
    cout << "调用了cgirl func1()" << endl;
    char c =8;
    return c;
    //return 8;
}

int main()
{
    // cgirl g1(8);         //常规写法
    // cgirl g1=cgirl(8);  //显示转换
     cgirl g1 =8;        //隐式转换
    // cgirl g1;           //创建对象
    // g1 = 8;             //创建cgirl(8)临时对象,再赋值给g3
    // cgirl g1 = 0.8;
     g1.show();
    //func(8);
    //g1 = func1();
    //g1.show();
}
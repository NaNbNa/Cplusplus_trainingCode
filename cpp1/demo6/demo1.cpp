#include <iostream>
#include <initializer_list>

using namespace std;        //c11新标准--只读变量和常量,委托构造函数和继承构造 

double sum(std::initializer_list<double> il)
{
    double total = 0;
    for(auto it = il.begin();it!=il.end();it++)
    {
        total = total + *it;
    }
    return total;
}

void func(const int len1)
{
    //int array1[len1];     //vs是false,Linux是true,vs中len1是只读变量,不可初始化数组

    constexpr int len2 = 8; //len2是常量,const同义,但建议用constexpr
    int array2[len2] = {0};
}

class cgirl
{
private:
    int m_bh =20;
    string m_name = "美女";
    char m_xb = 'X';
public:
    cgirl()=default;    //使用默认函数
    cgirl(int bh,string name):m_bh(bh),m_name(name){}
    //cgirl(const cgirl& g)= delete;    //禁用默认函数
    void show()
    {
        cout << "m_bh= " << m_bh << ", m_name= " << m_name <<endl;
    }
    //~cgirl(){}
};

class AA
{
// private:
//     double m_c;
public:
    int m_a;
    int m_b;
    AA(double c):m_a(c)
    {
        cout << "AA(double c)" <<endl;
    }
    AA(int a,int b):m_a(a),m_b(b)
    {
        cout << "AA(int a,int b)" <<endl;
    }
    AA(int a, int b,const string& str):AA(a,b)      //委托构造函数,不要生成环状构造过程
    {
        cout << "AA(int a, int b,const string& str)" << ", m_a=" << m_a 
            << ", m_b=" << m_b << ", str=" << str <<endl;
    }
    AA(double c,const string& str):AA(c)//,m_a(0)   //false,委托构造不可再初始化其他变量
    {
        cout << "AA(double c,const string& str)" << ", m_c=" << m_a
            << ", str=" << str << endl;
    }
};

class BB: public AA
{
private:
    double m_c;
public:
    using AA::AA;      //继承AA的构造函数,即含有AA的全部构造函数
    BB(int a,int b,double c):AA(a,b),m_c(c)         //可初始化其他变量
    {
        cout << "BB(int a,int b,double c)" <<endl;
    }
    void show()
    {
        cout << "m_a=" << m_a << ", m_b= " << m_b 
            << ", m_c=" << m_c <<endl;
    }
};
int main()
{
    // double total = sum({3.14,5.20,8});
    // cout << "total=" << total <<endl;

    // cgirl g1;
    // //g1.show();
    // cgirl g2 = g1;

    // AA a1(10,20,"你是一只傻傻鸟");
    // AA a2(3.8,"你有一只傻傻鸟");

    BB b1(10);
    b1.show();

    BB b2(11,20);
    b2.show();

    BB b3(12,21,10.58);
    b3.show();

}
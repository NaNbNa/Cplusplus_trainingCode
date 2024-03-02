#include <iostream>
#include <string.h>

using namespace std;

class cgirl
{
public:
    int m_bh;
    string m_name;
    double m_weight;

    cgirl()
    {
        m_bh = 8;m_name ="西施";m_weight = 50.7;
    }
    explicit operator int()
    {
        cout << "调用了operator int()" << endl;
        return m_bh;
    }
    operator string()
    {
        cout << "调用了operator string()" << endl;
        return m_name;
    }
    operator double()
    {
        cout << "调用了operator double()" << endl;
        return m_weight;
    }

    int to_int()    //普通成员函数
    {
        return m_bh;
    }

};
int main()
{
    cgirl g;
    int a =g; cout << "a=" << a <<endl;     //隐式转换
    string b =(string)g; cout << "b=" << b <<endl;  //显式转换
    double c =double(g); cout << "c=" << c <<endl;  //显式转换,另一写法
    
    //short d = g;    //false, 二义性

    int i =g.to_int();  //普通成员函数更好
    cout << "i=" << i <<endl;
 }
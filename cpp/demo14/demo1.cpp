#include <iostream>
#include <string.h>

using namespace std;

template <typename T1, typename T2=string>  //缺省
class AA
{
public:
    T1 m_a;
    T2 m_b;

    AA(){}
    AA(T1 a, T2 b):m_a(a),m_b(b)
    {

    }

    T1 geta()
    {
        // T1 a =2;
        // return m_a+a;
        return m_a;
    }
    T2 getb();
    
};

template <typename T1, typename T2>     //函数外定义
T2 AA<T1,T2>::getb()
{
    //T2 b =1;
    //return m_b+b;
    return m_b;
}
int main()
{
    AA<int> a1; //缺省值string
    AA<int,string> a;
    a.m_a =50;a.m_b=40;
    cout << "m_a=" << a.geta() << ", m_b=" << a.getb() <<endl;

    AA<int> *pa = new AA<int>;                  //new一定要delete
    AA<int> *pa1 = new AA<int>(3,"string");     //new一定要delete

    cout << "pa->geta()=" << pa->geta() <<endl;
    cout << "pa->getb()=" << pa->getb() <<endl;

    cout << "pa1->geta()=" << pa1->geta() <<endl;
    cout << "pa1>getb()=" << pa1->getb() <<endl;
    
    delete pa;
    delete pa1;
}
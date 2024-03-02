#include <iostream>
using namespace std;

template<class T1, class T2>            //模板类中嵌套模板类和模板函数,还有在类外定义的写法
class AA
{
public:
    T1 m_x;
    T2 m_y;

    AA(const T1& x, const T2& y):m_x(x),m_y(y){}
    void show()
    {
        cout << "m_x=" << m_x << ", m_y=" << m_y <<endl;
    }

    template <class T> 
    class BB                   //嵌套模板类
    {
    public:
        T m_a;
        T1 m_b;
        void show();
        
    };

    BB<string> m_bb;
    template <typename T>       //嵌套模板函数
    void show(T& tt)
    {
        cout << "调用了show(T& tt)" <<endl;
        cout << "tt=" << tt <<endl;
        cout << "m_x=" << m_x << ", m_y=" << m_y <<endl;
        m_bb.show();
    }
};

template<class T1, class T2>
template <class T>
void AA<T1,T2>::BB<T>::show()       //函数外声明
{
            cout << "调用了BBshow()" <<endl;
             cout << "m_a=" << m_a << ", m_b=" << m_b <<endl;
}

int main()
{
    AA<int,string> a(88,"你是一只傻傻鸟");

    a.show();

    a.m_bb.m_a="西施";
    a.m_bb.show();

    a.show("西瓜");

}
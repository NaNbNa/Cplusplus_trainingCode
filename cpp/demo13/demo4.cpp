#include <iostream>
#include <string.h>

using namespace std;
class cgirl
{
public:
    int m_bh;
    string m_name;
    int m_rank;
};

template <typename T>
void swap1(T& a, T& b)
{
    T temp = a;
    a =b;
    b = temp;
    cout << "调用了swap1swap1(T& a, T& b)" <<endl;
}

template <>
void swap1(cgirl& a, cgirl& b);         //声明与定义分开,,但两部分都不能缺template <>



//template <> void swap1<cgirl>(cgirl& a, cgirl& b)
// template <> void swap1(cgirl& a, cgirl& b)
// {
//     int temp = a.m_rank;
//     a.m_rank = b.m_rank;
//     b.m_rank = temp;
//     cout << "调用了swap1(cgirl& a, cgirl& b)" <<endl;
// }

int main()
{
    int a=10,b=20;
    swap1(a,b);
    cout << "a=" << a << ", b=" << b <<endl;

    cgirl g1,g2;
    g1.m_rank =1 ;g2.m_rank=2;
    swap1(g1,g2);
    cout << "g1.m_ rank=" << g1.m_rank << ", g2.m_rank=" << g2.m_rank <<endl;
}

template <>
void swap1(cgirl& a, cgirl& b)
{
    int temp = a.m_rank;
    a.m_rank = b.m_rank;
    b.m_rank = temp;
    cout << "调用了swap1(cgirl& a, cgirl& b)" <<endl;
}
#include <iostream>
#include <string.h>

using namespace std;
class A1
{
public:
    int m_a =10;
};
class A2
{
public:
    int m_a =20;
};
class B:public A1,public A2
{
public:
    int m_a =30;
};
int main()
{
    B b;
    cout << "B::m_a=" << b.m_a <<endl;
    cout << "A1::m_a=" << b.A1::m_a <<endl;
    cout << "A2::m_a=" << b.A2::m_a <<endl;
}
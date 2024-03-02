#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

template <class T>
class girl
{
public:
    T m_yz;
    int m_count;

    girl(const T yz):m_yz(yz), m_count(0){}

    void operator()(const T& yz)
    {
        if(yz == m_yz) m_count++;
    }

};
int main()
{
    vector<int> vv = {1,3,2,4,1,2,3,1,4,3};

    girl<int> g = for_each(vv.begin(),vv.end(),girl<int>(1));   //按yz统计人数,返回类

    cout << "g.m_count= " << g.m_count <<endl;
}
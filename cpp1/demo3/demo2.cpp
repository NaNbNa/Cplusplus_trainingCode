#include <iostream>
#include <vector>
#include <algorithm>    //stl
#include <list>

using namespace std;        //实现了find_if的算法

template <class T>
class zs
{
public:
    T m_no;
    zs(const T& no):m_no(no){}

    bool operator()(const T& no)
    {
        if(no!=m_no) return false;

        cout << "亲爱的" << no << "号:你是一只傻傻傻鸟." <<endl;
        return true;
    }
};

template <typename T1,typename T2>
T1 findif(const T1 first,const T1 last,T2 pfun)
{
    for(auto it1 = first;it1!=last;it1++)
    {
        //cout << "亲爱的" << *it1 << "号:你是一只傻傻傻鸟." <<endl;
        //pfun.show1(*it1);
        if(pfun(*it1)==true) return it1;
    }
    return last;
}

template <typename T>
bool show(const T& no)
{
    if(no!=3) return false;

    cout << "亲爱的" << no << "号:你是一只傻傻傻鸟." <<endl;
    return true;
}

int main()
{
    vector<int> bh= {5,8,2,6,9,3,1,7};
    //vector<string> bh = {"05", "08", "02", "06", "09", "03", "01", "07"};
    //list<string> bh = {"05", "08", "02", "06", "09", "03", "01", "07"};
    //findif(bh);

    auto it = findif(bh.begin(),bh.end(),show<int>);
    if(it == bh.end()) cout << "查找失败" <<endl;
    else cout << "查找成功:" << *it <<endl;

    //zs czs;
    //zs<string> czs;
    //findif(++bh.begin(),--bh.end(),czs);

    auto it1 = findif(bh.begin(),bh.end(),zs<int>(33));   //匿名对象
    if(it1 == bh.end()) cout << "查找失败" <<endl;
    else cout << "查找成功:" << *it1 <<endl;

    it1 = find_if(++bh.begin(),--bh.end(),zs<int>(2));    //stl提供的算法
    if(it1 == bh.end()) cout << "查找失败" <<endl;
    else cout << "查找成功:" << *it1 <<endl;
}
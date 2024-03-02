#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;        //实现了for_each的算法

// void foreach(const vector<int>& v)
// {
//     for(auto it = v.begin();it!=v.end();it++)
//     {
//         cout << "亲爱的" << *it << "号:你是一只傻傻傻鸟." <<endl;
//     }
// }

template <class T>
class zs
{
public:
    void show1(const string& no)
    {
        cout << "亲爱的" << no << "号:你是一只傻傻傻鸟." <<endl;
    }

    void operator()(const T& no)
    {
        cout << "亲爱的" << no << "号:你是一只傻傻傻鸟." <<endl;
    }
};

template <typename T1,typename T2>
void foreach(const T1 first,const T1 last,T2 pfun)
{
    for(auto it = first;it!=last;it++)
    {
        //cout << "亲爱的" << *it << "号:你是一只傻傻傻鸟." <<endl;
        //pfun.show1(*it);
        pfun(*it);
    }
}

template <typename T>
void show(const T& no)
{
    cout << "亲爱的" << no << "号:你是一只傻傻傻鸟." <<endl;
}

// template <typename T>
// void foreach(const T first,const T last,void(*pfun)(const string&))
// {
//     for(auto it = first;it!=last;it++)
//     {
//         //cout << "亲爱的" << *it << "号:你是一只傻傻傻鸟." <<endl;
//         pfun(*it);
//     }
// }

// void foreach(const vector<string>::iterator first,const vector<string>::iterator last)
// {
//     for(auto it = first;it!=last;it++)
//     {
//         cout << "亲爱的" << *it << "号:你是一只傻傻傻鸟." <<endl;
//     }
// }

int main()
{
    vector<int> bh= {5,8,2,6,9,3,1,7};
    //vector<string> bh = {"05", "08", "02", "06", "09", "03", "01", "07"};
    //list<string> bh = {"05", "08", "02", "06", "09", "03", "01", "07"};
    //foreach(bh);
    //foreach(++bh.begin(),--bh.end(),show);

    //zs czs;
    //zs<string> czs;
    //foreach(++bh.begin(),--bh.end(),czs);
    //foreach(++bh.begin(),--bh.end(),zs<int>());   //匿名对象
    for_each(++bh.begin(),--bh.end(),zs<int>());    //stl提供的算法
}
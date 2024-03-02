#include <iostream>
#include <string.h>
#include <vector>

using namespace std;        //学习for(auto& val: v1)/for(auto val: v1):基于范围的for循环.
                            //v1是容器名等可迭代的对象,但不能是指针
                            //auto的使用场景总结:1.函数指针2.迭代器3.for的范围循环
                            //for的范围循环:本质利用了迭代器,注意迭代器失效

class AA
{
public:
    string m_name;

    AA()
    {
        cout << "默认构造函数AA()" <<endl;
    }

    AA(const string& name):m_name(name)
    {
        cout << "构造函数/转换函数" << ", name=" << m_name <<endl;
    }

    AA(const AA& a):m_name(a.m_name)
    {
       cout << "拷贝构造函数" << ", name=" << m_name <<endl;
    }

    AA& operator=(const AA& a)
    {
        m_name = a.m_name;
        cout << "赋值函数, name=" << m_name <<endl;
        return *this;
    }

    ~AA()
    {
        cout << "析构函数, name=" << m_name <<endl;
    }
};
int main()
{
    // vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};            //验证迭代器失效
    // int i=0;
    // for(auto it2 = v1.begin();it2!=v1.end();it2++,i++)         //auto关键字
    //     {
    //         cout << *it2 << "\t";
    //         if((i+1)%5==0) cout <<endl;
    //     }
    // cout << endl;

    // for(int val: v1)
    // {
    //     cout << val << " ";
    // }
    // cout <<endl;

    // for(auto val: {1,2,3,4,5,6,7,8,9,10})
    // {
    //     cout << val << " ";
    // }
    // cout <<endl;

    // vector<AA> v;
    // cout << "------------- v.capacity()=" << v.capacity() <<endl;
    // v.emplace_back("西施");
    // cout << "------------- v.capacity()=" << v.capacity() <<endl;
    // v.emplace_back("冰冰");
    // cout << "------------- v.capacity()=" << v.capacity() <<endl;
    // v.emplace_back("咪咪");
    // cout << "------------- v.capacity()=" << v.capacity() <<endl;

    // for(auto val:v) //赋值,需要每次调用拷贝构造函数和析构函数
    //     cout << val.m_name <<"\t";
    // cout <<endl;

    // for(auto& val:v)    //指针指向,不需要每次...,就是分配地址
    //     cout << val.m_name <<"\t";
    // cout <<endl;

    // for(const auto& val:v)    //指针指向,不需要每次...,就是分配地址
    //     cout << val.m_name <<"\t";
    // cout <<endl;

    vector<int> vv = {1,2,3,4,5,6,7,8,9,10};    //迭代器失效
    for(auto val:vv)
    {
        cout << val << " ";
        vv.push_back(10);     //追加10,导致迭代器失效
    }
    cout <<endl;
}
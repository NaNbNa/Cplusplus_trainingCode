#include <iostream>
#include <string.h>

using namespace std;    //模板类作为参数
                        //重点理解模板的模板:主要用于数据结构--template<class,int>class tabletype
                        //函数不支持模板的模板

template <class T,int len>  //模板
class linkList1
{
public:
    T* m_head;
    int m_len =len;
    void insert()
    {
        cout << "向链表插入了一个数据" <<endl;
    }

    void ddelete()
    {
         cout << "向链表删除了一个数据" <<endl;
    }
    void update()
    {
        cout << "向链表更新了一个数据" <<endl;
    }
};

template <class T,int len>      //模板
class Array1
{
public:
    T* m_data;
    int m_len =len;
    void insert()
    {
        cout << "向数组插入了一个数据" <<endl;
    }
    void ddelete()
    {
         cout << "向数组删除了一个数据" <<endl;
    }
    void update()
    {
        cout << "向数组更新了一个数据" <<endl;
    }
};

template<template<class,int>class tabletype,class datatype, int len>   //模板的模板的代码
                    //template<class,int>class tabletype:意思是要填模板名,带<class,int>的模板名tabletype
class LinearList    //线性表
{
public:
    tabletype<datatype,len> m_table;
    void insert()
    {
        m_table.insert();
    }
    void ddelete()
    {
        m_table.ddelete();
    }
    void update()
    {
        m_table.update();
    }

    void oper()     //按照业务操作线性表
    {
        cout << "len=" << m_table.m_len <<endl;
        m_table.insert();
        m_table.update();
    }
};

int main()
{
    LinearList<linkList1,int,20> a;
    a.insert();
    a.ddelete();
    a.update();

    LinearList<Array1,int,20> a1;
    a1.insert();
    a1.ddelete();
    a1.update();
}
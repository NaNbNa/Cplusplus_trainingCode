#include <iostream>
#include <string.h>
#include <vector>
using namespace std;        //vector容器的全部使用办法--本质是数组,插入和删除操作效率低下

class AA
{
public:
    int m_bh;
    string m_name;

    AA()
    {
        cout << "调用了构造函数AA()" <<endl;
    }

    AA(const int& bh,const string& name):m_bh(bh),m_name(name)
    {
        cout << "构造函数, name=" << name << endl;
    }

    AA(const AA& a)
    {
        cout << "拷贝构造函数, name=" << a.m_name << endl;
        m_name = a.m_name; m_bh = a.m_bh;
    }

    ~AA()
    {
        cout << "调用了析造函数~AA()" <<endl;
    }
};
int main()
{
    // vector<int> v;
    // cout << "v的首地址v.data():" << v.data() <<endl;
    // cout << "v.capacity()=" << v.capacity() << ", v.size()=" 
    // << v.size() <<endl;

    // cout << "---------------------------" <<endl;
    // vector<int> v1(8);                  //带explicit的构造函数
    // cout << "v1的首地址v.data():" << v1.data() <<endl;
    // cout << "v.capacity()=" << v1.capacity() << ", v.size()=" 
    // << v1.size() <<endl;

    // cout << "---------------------------" <<endl;
    // vector<int> v2{1,5,2,4,3};          //初始化列表式的构造函数
    // cout << "v2的首地址v.data():" << v2.data() <<endl;
    // for(int ii=0;ii<v2.size();ii++)
    // {
    //     cout << "v2[" << ii << "]=" << v2[ii] <<"\t";
    // }
    // cout <<endl;

    // vector<int> v3={1,5,2,4,3};
    // v3.data()[0] = 8;           //数组表示法
    // v3.data()[1] = 7;           
    // *((v3.data())+2) = 5;       //指针表示法
    // *((v3.data())+3) = 4;
    // for(int ii=0;ii<v2.size();ii++)
    // {
    //     cout << "v3[" << ii << "]=" << v3[ii] <<"\t";
    // }
    // cout <<endl;

    // vector<int> v1;             //三个赋值操作
    // v1 = {1,2,3,4,5};       
    // for(int ii=0;ii<v1.size();ii++)
    //     cout << "v1[" << ii << "]=" << v1[ii] <<"\t";
    // cout <<endl;

    // vector<int> v2;
    // v2 = v1;
    // for(int ii=0;ii<v1.size();ii++)
    //     cout << "v2[" << ii << "]=" << v2[ii] <<"\t";
    // cout <<endl;

    // vector<int> v3;
    // v3.assign({1,3,2,4,5});
    // for(int ii=0;ii<v1.size();ii++)
    //     cout << "v3[" << ii << "]=" << v3[ii] <<"\t";
    // cout <<endl;

    // int a;
    // vector<int> v;

    // a=1;v.push_back(a);  //两个插入函数
    // a=2;v.push_back(a);
    // a=3;v.push_back(a);

    // for(int ii=0;ii<v.size();ii++)
    // {
    //     cout << "v3[" << ii << "]=" << v[ii] <<"\t";
    // }
    // cout <<endl;

    // //AA a(18,"西施");
    // vector<AA> v;
    // //v.push_back(a);     //调用了拷贝构造函数,因为是函数,形参调用了拷贝构造函数
    // //v.emplace_back(a);      //调用了拷贝构造函数
    // v.emplace_back(18,"西施");  //调用了构造函数,即AA a(18,"西施")可省略

    // cout << "bh=" << v[0].m_bh << ", name=" << v[0].m_name <<endl;


    vector<vector<int>> vv;
    vector<int> v;

    v={1,2,3,4,5};
    vv.push_back(v);
    
    v = {11,12,13,14,15,16,17};
    vv.push_back(v);

    v = {21,22,23};
    vv.push_back(v);

    for(int ii=0;ii<vv.size();ii++)
    {
        for(int jj=0;jj<vv[ii].size();jj++)
            cout << "vv[" << ii << "][" << jj << "]=" << vv[ii][jj] <<"\t";
         cout <<endl;
    }
   
}
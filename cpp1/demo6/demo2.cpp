#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show(const int& no)
{
    cout << "亲爱的" << no << "号: 你是一只傻傻鸟" << endl;
}

class czs
{
public:
     void operator()(const int& no)
     {
        cout << "亲爱的" << no << "号: 你是一只傻傻鸟" << endl;
     }
};

class myclass       //传值lambda等价
{
    int m_a;
public:
    myclass(int a):m_a(a){}
    int operator()(const int c) const   
    {
        return m_a + c;
    }
};
int main()
{
    vector<int> vv = {5,8,3};

    //for_each(vv.begin(),vv.end(),show);

    //for_each(vv.begin(),vv.end(),czs());

    // for_each(vv.begin(),vv.end(),
    // [](const int& no){
    //     cout << "亲爱的" << no << "号: 你是一只傻傻鸟" << endl;
    // }
    int ii =3;double dd = 8.1;
    //auto f = [ii,&dd](const int& no) {
    //auto f = [=, &dd](const int& no) {
    auto f = [&,ii](const int& no) {
        cout << "ii=" << ii <<endl;
        cout << "dd=" << ++dd <<endl;
        cout << "亲爱的" << no << "号: 你是一只傻傻鸟" << endl;
    };
    //for_each(vv.begin(),vv.end(),f);
    f(33);
}
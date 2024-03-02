#include <iostream>
#include <functional>
using namespace std;        //绑定器bind

void show(int bh,const string& str)
{
    cout << "亲爱的" << bh << "号, " << str <<endl;
}

int main()
{
    function<void(int,const string&)> fn1 =show;
    function<void(int,const string&)> fn2 =bind(show,placeholders::_1,placeholders::_2);

    fn1(1,"你是一只傻傻傻鸟");
    fn2(2,"你是一只傻傻傻鸟");

    function<void(const string&,int)> fn3 = bind(show,placeholders::_2,placeholders::_1);
    fn3("你是一只傻傻傻鸟",3);

    int bh = 4;
    //function<void(const string&)> fn4 = bind(show,bh,placeholders::_1);
    function<void(const string&)> fn4 = bind(show,std::ref(bh),placeholders::_1);
    bh =8;
    fn4("你是一只傻傻傻鸟");

    // function<void(int,const string&,int)> fn5 = bind(show,placeholders::_2,placeholders::_1);    //false
    // fn5(5,"你是一只傻傻傻鸟",5);
}
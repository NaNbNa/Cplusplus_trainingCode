#include <iostream>
#include <string.h>
#include <functional>
using namespace std;    //6个可调用对象的绑定器bind
                        //

void show(int bh,const string& str)
{
    cout << "亲爱的" << bh << "号, " << str <<endl;
}

class AA    //静态成员函数
{
public:
    static void show(int bh,const string& str)
    {
        cout << "亲爱的" << bh << "号, " << str <<endl;
    }
};

struct BB   //仿函数
{
    void operator()(int bh,const string& str)
    {
        cout << "亲爱的" << bh << "号, " << str <<endl;
    }
};

struct CC
{
    void show(int bh,const string& str)
    {
        cout << "亲爱的" << bh << "号, " << str <<endl;
    }
};

struct DD
{
    using fun = void(*)(int,const string&); //函数指针别名,不是函数类型别名
    operator fun()
    {
        return show;
    }
};

int main()
{    
    //普通函数
    function<void(int,const string&)> fn1 = bind(show,placeholders::_1,placeholders::_2);
    //function<fun> fn1 = show;
    fn1(1,"你是一只傻傻傻鸟");

    //静态成员函数
    function<void(int,const string&)> fn3 = bind(AA::show,placeholders::_1,placeholders::_2);
    fn3(2,"你是一只傻傻傻鸟");

    BB bb;
    //对象使用仿函数
    function<void(int,const string&)> fn4 = bind(bb,placeholders::_1,placeholders::_2);
    //function<void(int,const string&)> fn4 = bind(BB(),placeholders::_1,placeholders::_2);
    fn4(3,"我是一只傻傻鸟");
    //BB()(12,"我是一只小小鸟");    //匿名对象


    auto lb = [](int bh,const string& str)       //lambda
    {
        cout << "亲爱的" << bh << "号, " << str <<endl;
    };
    lb(4,"我是一只傻傻鸟");
    function<void(int,const string&)> fn5 = bind(lb,placeholders::_1,placeholders::_2);
    //auto fn5 = bind(lb,placeholders::_1,placeholders::_2);
    fn5(4,"我是一只傻傻鸟");


    //void(CC::*fp1)(int,const string&) = &CC::show;    //类的普通成员函数无函数类型
    CC cc;
    //function<void(CC&,int,const string&)> fn11 =bind(&CC::show,placeholders::_1,placeholders::_2,placeholders::_3); 
    function<void(int,const string&)> fn11 =bind(&CC::show,&cc,placeholders::_1,placeholders::_2);
    fn11(5,"我是一只傻傻鸟");

    DD dd;
    function<void(int,const string&)> fn6 = bind(dd,placeholders::_1,placeholders::_2);
    fn6(6,"我是一只傻傻鸟");

    function<void(int,const string&)> fx;       //重载bool
    if(fx)      //判断包装了可调用对象
        fx(6,"我是一只傻傻鸟");
}

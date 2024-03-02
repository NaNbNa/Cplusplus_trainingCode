#include <iostream>
#include <string.h>

using namespace std;    //可调用对象:函数类型
                        //最特殊:类的普通成员函数

using fun = void(int,const string&);
fun show;   //普通函数

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
int main()
{
    // show(1,"你是一只傻傻傻鸟");      //普通函数

    // //void(*fp1)(int,const string&) = show;
    // auto fp1 = show;
    // //void(&fp2)(int,const string&) = show;
    // auto& fp2 = show;
    // fp1(2,"你是一只傻傻傻鸟");
    // fp2(3,"你是一只傻傻傻鸟");

    // fun* fp3 = show;
    // fun& fp4 = show;
    // fp3(4,"你是一只傻傻傻鸟");
    // fp4(5,"你是一只傻傻傻鸟");

    // AA::show(1,"你是一只傻傻鸟");        //静态成员函数
    
    // auto fp1 = AA::show;
    // auto& fp2 = AA::show;
    // fp1(2,"你是一只傻傻傻鸟");
    // fp2(3,"你是一只傻傻傻鸟");

    // fun* fp3 = AA::show;
    // fun& fp4 = AA::show;
    // fp3(4,"你是一只傻傻傻鸟");
    // fp4(5,"你是一只傻傻傻鸟");

    // BB bb;
    // bb(11,"我是一只傻傻鸟");      //对象使用仿函数
    // BB()(12,"我是一只小小鸟");    //匿名对象
    

    // BB& br = bb;
    // br(13,"我是一只傻傻鸟");

    // auto lb = [](int bh,const string& str)       //lambda
    // {
    //     cout << "亲爱的" << bh << "号, " << str <<endl;
    // };

    // auto& lr =lb;
    // lb(1,"我是一只傻傻鸟");
    // lr(2,"我是一只傻傻鸟");

    //void(CC::*fp1)(int,const string&) = &CC::show;    //类的普通成员函数无函数类型
    auto fp1 = &CC::show;
    CC cc;
    (cc.*fp1)(1,"我是一只傻傻鸟");

    using pfun = void(CC::*)(int,const string&);
    pfun fp2 = &CC::show;
    (cc.*fp2)(2,"我是一只傻傻鸟");
}

void show(int bh,const string& str)
{
    cout << "亲爱的" << bh << "号, " << str <<endl;
}
// fun show(int bh,const string& str)       //false
// {
//     cout << "亲爱的" << bh << "号, " << str <<endl;
// }
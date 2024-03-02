#include <iostream>

using namespace std;

void zs(int a)   //张三
{
    cout <<"a = " << a << "你要翻三个跟斗再表白!" <<endl;
}

void ls(int a)   //李四
{
     cout <<"a = " << a << "你有一只小小鸟!" <<endl;
}

void show(void (*pfc)(int),int b)        //个性化表白函数
{
    cout << "表白前的准备已完成!" <<endl;
    pfc(b);
    cout << "表白后的收尾已完成!" <<endl;
}
// void func(int no, string str)
// {
//     cout << "亲爱的" << no << "号: " << str <<endl;
// }
int main()          //函数指针和回调函数
{
    // int bh =3;
    // string message = "你是一只傻傻鸟!";

    // func(bh, message);

    // void (*pfc)(int ,string);
    // pfc = func;
    // pfc(bh, message);

    show(zs, 3);       //回调函数
    show(ls, 4);
}
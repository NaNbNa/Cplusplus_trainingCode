#include <iostream>
#include <string.h>

using namespace std;        //decltype:注意与auto的差别

template <typename T1,typename T2>
auto func1(T1 x, T2 y)->decltype(x+y)
{
    //??? temp = x +y
    decltype(x+y) temp = x+y;
    cout << temp << endl;
    return temp;
}
// int func()
// {
//     cout << "调用了func()函数" <<endl;
//     return 3;
// }
int main()
{
    // double a = 5.5;
    // int b =3;
    //auto temp = a +b;
    //func(a,b);

    // short a =5;
    // short& ra = a;

    // short b =1;
    // decltype(ra) db = b;

    //cout << db  <<endl;

    // decltype(func()) df3=10;   //int
    // decltype(func) df1;      //df是函数的类型
    // decltype(func) *df = func;     //df是函数指针的类型
    // decltype((func)) df2 =func;    //df2:int (&df2)
    // //df2();
    // //df();
    

    // decltype(++a) da =a ;       //++a是表达式,左值. da:short&
    // decltype(a)  da1 =1;        //da1:short
    // decltype((a)) da2 =a;       //da2:short&

    // decltype(func()) dd = 10;   //不会调用func()
    // auto dd1 = func();          //会调用func()

    auto  c= func1(2,3.5);
    cout << "c=" << c <<endl;
}
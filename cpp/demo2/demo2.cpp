#include <iostream>

using namespace std;        //变量的作用域-全局变量,局部变量,**静态(局部)变量

                            //静态(局部)变量生命周期与所在函数无关,与程序相同
                            //只初始化一次,而且作用域与所初始化的函数使用
int a = 11;      //自动初始化为0
void func1();
void func2();

int main()
{
    //A = 10;
    //func1();

    func2();
    func2();
    func2();

    //cout << "main A = " << A << endl;
}

void func1()
{   
    int xx = 19;
    cout << "func1 xx =" << xx++ << endl;
    cout << "func1 A = " << a++ << endl;
}

void func2()
{
    static int a = 10;
    int b = 10;
    cout << "func2 a =" << a++ <<endl;
    cout << "func2 b =" << b++ <<endl;
    //cout << "func2 A = " << A++ <<endl;
}
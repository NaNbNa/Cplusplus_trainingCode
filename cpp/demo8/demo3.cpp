#include <iostream>

using namespace std;        //重载的细节
                            //自动类型转换,引用,默认参数都可能导致重载失败
                            //const 无意义,不是特征,

void show(short bh,string message)
{
    cout << "short!" <<endl;
}

void show(short bh,string& message)
{
    cout << "&short!" <<endl;
}
// void show(double bh,string message)
// {
//     cout << "double!" <<endl;
// }

// void show(long bh,string message)
// {
//     cout << "long!" <<endl;
// }

int main()
{
    short bh =10;

    show(bh,"你是一只傻傻鸟!");

    cout << "ok" <<endl;
}
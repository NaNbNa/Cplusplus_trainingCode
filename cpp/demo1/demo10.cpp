#include <iostream>

using namespace std;

int main()     //运算符的优先级
{
    int a, b, c, d;

    // a = b = c = 10;  //从右到左执行赋值

    // cout << "a = " << a <<endl;

    a= 4, b= 9, c=13;

    d = a * b %c;
    cout << d << endl;


}
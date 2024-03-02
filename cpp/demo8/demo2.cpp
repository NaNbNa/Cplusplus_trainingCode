#include <iostream>

using namespace std;    //重载函数

void myswap(int& a,int& b)
{
    int temp = a; a=b; b =temp;
}

void myswap(string& a,string& b)
{
    string temp = a; a=b; b = temp;
}

int main()
{
    int a= 3, b=5;

    myswap(a,b);
    cout << "a = " << a << ", b = " << b <<endl;

    string c= "西施", d="冰冰";

    myswap(c,d);
    cout << "c = " << c << ", d = " << d <<endl;
 }
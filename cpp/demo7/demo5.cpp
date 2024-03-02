#include <iostream>

using namespace std;  //引用作为返回值
                        //具有一个特性:函数是别名!,需要加const保护

int func1()
{
    int ii= 3;
    return ii;
}

const int& func2(int& ra)
{
    ra ++ ;
    cout << "ra的地址是: " << &ra <<  "ra = " << ra << endl;
    return ra;
}
int main()          
{
    int a =3;
    //int a = func1(); cout << "a = " << a << endl; //返回的是值
    const int& b =func2(a); //cout << "b = " << b << endl; //返回的是地址
    cout << "a的地址是: " << &a <<  "a = " << a << endl;
    cout << "b的地址是: " << &a <<  "b = " << a << endl;
}
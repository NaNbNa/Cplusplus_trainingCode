#include <iostream>
#include <string.h>

using namespace std;

class cgirl
{
public:
   
    cgirl()
    {

    }
    template <typename T>
    cgirl(T a)
    {
        cout << "a=" << a <<endl;
    }

    template <typename T>
    void show(T b)
    {
        cout << "b=" << b <<endl;
    }
};

template <typename T>
void swap1(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
void swap1()                            //无参数
{
    cout << "调用了swap1()" <<endl;
}

template <typename T1, typename T2>     //多个参数
void swap1(T1 no, T2 mes)
{
    cout << no << "," << mes <<endl;
}
template <typename T>       //返回值
T add(T a, T b)
{
    return a +b;
}
int main()
{
    // cgirl g("西施");
    // g.show(2);
    // g.show("冰冰");
    // char a = 80;
    // char b =90;
    // cout << "a=" << a << ", b=" << b <<endl;
    // swap1(a,b);
    // cout << "a=" << a << ", b=" << b <<endl;

    // swap1<int>();      //无参数,需要显式的指定数据类型

    // string a ="西施";
    // string b ="西瓜";
    // cout << add(a,b) <<endl;

    // cgirl a;
    // cgirl b;
    // cout << add(a,b) <<endl;  //false

    // int a =80;
    // char b = 10;
    // //cout << add(a,b) <<endl; //false
    // cout << add<int>(a,b) <<endl;    //显式指定int后,进行了隐式类型转换

    int a =3;int b=4;
    swap1(3,"你好");        //重载
    swap1<int>();
    swap1(a,b);
    cout << "a=" << a << ", b=" << b <<endl;

}
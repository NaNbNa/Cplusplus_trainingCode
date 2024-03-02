#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
void swap1(T& a, T& b)
{
    T temp= a;
    a = b;
    b =temp;
}

// void swap1(int& a,int& b)
// {
//     int temp = a;
//     a= b;
//     b = a;
// }

// double swap1(double& a,double& b)
// {
//     double temp = a;
//     a= b;
//     b = a;
// }

int main()
{
    int a=10, b=30;
    cout << "a=" << a << ",b=" << b <<endl;
    swap1(a,b);
    //swap1<int>(a,b);      //指定a,b是int类型
    cout << "a=" << a << ",b=" << b <<endl;
}
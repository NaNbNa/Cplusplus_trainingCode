#include <iostream>
using namespace std;

void swap1(int a, int b);

template <typename T>
void swap1(T a, T b)
{
    cout << "使用了函数模板" << endl;
}

template <>
void swap1(int a, int b);


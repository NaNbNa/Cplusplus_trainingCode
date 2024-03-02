#include "demo6.h"

void swap1(int a, int b)
{
    cout << "使用了普通函数" << endl;
}

template <>
void swap1(int a, int b)
{
    cout << "使用了具体化的函数模板" << endl;
}
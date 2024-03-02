#include <iostream>
#include <string.h>

using namespace std;            //普通+重载+模板+具体化,选择的优先级

void swap1(int a, int b)
{
    cout << "使用了普通函数" << endl;
}
template <typename T>
void swap1(T a, T b)
{
    cout << "使用了函数模板" << endl;
}

template <>
void swap1(int a, int b)
{
    cout << "使用了具体化的函数模板" << endl;
}

int main()
{
    swap1(1,2);         //普通+重载+模板+具体化,选择的优先级
    swap1<>(1,2);         //不想使用普通函数

    swap1('c','d');     //模板匹配比普通更好
                        //而且找不到与函数调用匹配的具体化定义(具体化是int,函数调用是char)
}
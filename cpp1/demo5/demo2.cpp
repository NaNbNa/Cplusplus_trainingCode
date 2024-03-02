#include <iostream>
using namespace std;    //避免异常:特别是new

int main()
{
    double* ptr =nullptr;   //未初始化会造成操作野指针
    // try
    // {
    //     /* code */
    //     ptr = new double[10000000000];
    // }
    // catch(bad_alloc& e)
    // {
    //     cout <<"分配失败" <<endl;
    // }
    
    ptr = new(std::nothrow) double[10000000000];    //不抛异常的版本

    cout << "程序继续运行..." <<endl;

    if(ptr!=nullptr) delete[] ptr;
}
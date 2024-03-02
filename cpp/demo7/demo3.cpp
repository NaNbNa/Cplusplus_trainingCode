#include <iostream>

using namespace std;        //引用与二级指针--在函数中动态分配内存是需要二级指针或引用

void func1 (int** p)
{
    *p = new int(3);
    cout << "func1内存的地址是:" << *p << ", 内存中的值是:" << **p <<endl;
}
void func2 (int*& p)
{
    p = new int(3);
    cout << "func2内存的地址是:" << p << ", 内存中的值是:" << *p <<endl;
}

int main()
{
    int* p = nullptr;

    //func1(&p);
    func2(p); 

    cout << "main内存的地址是:" << p << ",内存中的值:" << *p <<endl; 
}
#include <iostream>

using namespace std;

void func(string varname, void* p);

int main()          //void类型的使用
{
    int a = 89;
    char b = 'X';

    cout << "a的地址是:" << &a <<endl;
    cout << "b的地址是:" << &b <<endl;     //显示会有错误,cout的bug

    func("a", &a);
    func("b", &b);   
 }

 void func(string varname, void* p)
{
    cout << varname << "的地址是:" << p <<endl;
    cout << varname << "的地址值是:" << *(char *)p <<endl;
}
#include <iostream>

using namespace std;

int main()          //打印地址,cout有bug,显示地址把地址当作string
                    //void*可以接受任意指针,意思是可以完整接受地址
{
    int a ;
    char b ;
    bool c ;
    string d;
    
    int* pa = (int*)&b;
    char* pb = (char*)&a;
    bool* pc = &c;
    string* pd = &d;

    // cout << "变量a的地址是:" << &a << endl;
    // // 显示带问题
    // cout << "变量b的地址是:" << &b << endl;         
    // cout << "变量c的地址是:" << &c << endl;
    // cout << "变量d的地址是:" << &d << endl;

    cout << "sizeof (pa) = " << sizeof(pa) << ",sizeof(int*) = " << sizeof(int*) << endl;
    cout << "sizeof (pb) = " << sizeof(pb) << ",sizeof(char*) = " << sizeof(char*) << endl;
    cout << "sizeof (pc) = " << sizeof(pc) << ",sizeof(bool*) = " << sizeof(bool*) << endl;
    cout << "sizeof (pd) = " << sizeof(pd) << ",sizeof(string*) = " << sizeof(string*) << endl;

    //法一
    cout << "变量a1的地址是:" << (void*)&a << endl;
    cout << "变量b1的地址是:" << (void*)&b << endl;         
    cout << "变量c1的地址是:" << (void*)&c << endl;
    cout << "变量d1的地址是:" << (void*)&d << endl;

    cout << "变量pa的地址是:" << (void*)pa << endl;
    cout << "变量pb的地址是:" << (void*)pb << endl;         
    cout << "变量pc的地址是:" << (void*)pc << endl;
    cout << "变量pd的地址是:" << (void*)pd << endl;
    // //法二
    // cout << "变量a2的地址是:" << (long long)&a << endl;
    // cout << "变量b2的地址是:" << (long long)&b << endl;         
    // cout << "变量c2的地址是:" << (long long)&c << endl;
    // cout << "变量d2的地址是:" << (long long)&d << endl;
}
#include <iostream>

using namespace std;

int main()
{
    // int a; 
    // char b; 
    // bool c;
    // string d;

    // int* pa;
    // char* pb;
    // bool* pc;
    // string* pd;

    // a =1;

    int a =3; 
    int* p = &a;
    int* p1 = &a;
    cout << "a = " << a << ", p = " << *p <<endl;
    cout << "a = " << a << ", p1 = " << *p <<endl;

    *p1 = 8;
    cout << "a = " << a << ", p = " << *p <<endl;
    cout << "a = " << a << ", p1 = " << *p <<endl;
    
}
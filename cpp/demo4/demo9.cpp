#include <iostream>

using namespace std;

int* func()
{
    int a =3;
    cout << "a = " << a << endl;
    return &a;
}
int main()      //  野指针
{
    int* p =func();

    // cout << "p = " << p << ", *p = " << *p <<endl;

    // delete p;

    cout << "p = " << p << ", *p = " << *p <<endl;


}
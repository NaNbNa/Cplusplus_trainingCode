#include <iostream>

using namespace std;

int main()      //bool的用法,本质是整数,关注cin用法,本质是unsigned char
{
    bool a = true , b = false ;

    // cout << "a = "; cin >> a;

    // cout << "sizeof(a) = " << sizeof(a) 
    //      << ", a = " << a << ", b = " << b <<endl;
    // cout << " a + b = " << a + a + a + b <<endl;


    char* c = (char*)&b;
    *c = 255;
    cout << "b = " << b <<endl;
 }
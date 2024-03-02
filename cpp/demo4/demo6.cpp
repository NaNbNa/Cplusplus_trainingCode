#include <iostream>

using namespace std;

int main()          //动态分配内存
{
    int* p;
    p = new int(5);

    cout << "*p = " <<  *p << endl;

    *p = 8;
     cout << "*p = " <<  *p << endl;

    delete p;
}
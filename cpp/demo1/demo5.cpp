#include <iostream>

using namespace std;

int main()      //自增和自减，++在前面和后面的区别
{
    int i = 10;
    int a = i++;
    cout <<  " i = "  << i++ <<endl;
    cout << " a = " << a++ << endl;
}
#include <iostream>

using namespace std;

int main()      //逻辑运算
{
    // bool a = 1;
    // bool b = 0;

    // bool c = 7 < 3 || b;
    // cout <<"c = " <<  !c << endl;
    // cout << (a && b) << endl;
    int age = 23;
    int height = 168;
    double weight = 48.8;
    bool yz = 1;

    cout <<" 是否是超女：" <<  (age < 25 && height > 165 && weight < 50 && yz) << endl;

}
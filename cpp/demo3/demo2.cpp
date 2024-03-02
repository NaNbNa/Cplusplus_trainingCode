#include <iostream>
#include <stdio.h>
using namespace std;

int main()      //测试浮点型数据-float -7, double -15~16,实际开发多用整数替代浮点数
                //如:1.75m,替换成175cm
{
    
    // cout << "sizeof(float) = " << sizeof(float) << endl; 
    // cout << "sizeof(double) = " << sizeof(double) << endl;
    // cout << "sizeof(long double) = " << sizeof(long double) << endl;
    float aa = 12345123.456789; cout << "aa = " << aa <<endl;
    double bb = 123451230123456789.456789; cout << "bb = " << bb <<endl;
    long double cc = 123451230123456789.456789; cout << "cc = " << cc <<endl;
    printf("aa = %lf\n", aa);
    printf("bb = %lf\n", bb);
    printf("cc = %lf\n", cc);    
}
#include <iostream>

using namespace std;

int main()          //数据类型的转换--起因:存储大小和存储方式不同
                    //强制类型转换--会使警告消失,也是运算符,注意优先度
{
    // char a = 30;
    // int b = 102400;
    // long long c = 1500000000001;

    // //精度: 有低有高,将低转为高
    // cout << "a + b + c = " << a + b + c <<endl;

    // // 精度:舍弃
    // cout << "8/5 = " << 8/5 <<endl;
    // cout << "8.0/5 = " << 8.0/5 <<endl;


    // //int d = 'X';
    // int d = 23.85;  //降低精度
    // cout << "d = " << d <<endl;

    // unsigned int e = 4294967295;
    // cout << "e = " << e <<endl;
    // unsigned int e1 = 4294967295+2;  //截断,从高位截断
    // cout << "e1 = " << e1 <<endl;

    //强制类型转换--会使警告消失,也是运算符,注意优先度
    cout << "8/5 = " << (float) 8/5 <<endl;
    unsigned int e1 = (unsigned int)4294967295+2;  //无警告
    cout << "e1 = " << e1 <<endl;
    cout << "8/5 = " << (double)(8/5) << endl; //优先级
}
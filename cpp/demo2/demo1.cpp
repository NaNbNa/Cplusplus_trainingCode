#include <iostream>

using namespace std;        //函数声明和定义, 函数的位置
                            //函数的调用--调用main函数会出现死循环

int max (int a, int b);      //比较a,b;返回较大值
void print(int no,string str);      //打印参数的值
void printMt();              //打印九九乘法表

int main()      
{   
    int a = 5, b = 8;
    cout << "max(" << a  << "," << b <<") = " << max(a,b) << endl;
    
    if (max(5,9)> 9)
        print(12, "我超喜欢你MM!");

    printMt();

}

int max (int a, int b)    
{
    return a > b ? a : b;
}
void print(int noo,string str1)
{
    cout << "亲爱的" << noo << "号超女:" << str1 << endl;
    return ;
}
void printMt()
{
     for (int i = 1;i <= 9; i++)     //九九乘法表
    {
        for (int j =1; j <=i;j++)
        {
            cout <<  i << "*" << j << "=" << i*j << " ";
        }
        cout << endl;
    }
    return ;
}
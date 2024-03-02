#include <iostream>

using namespace std;

void func(int* no,string* str);
void func1(int a, int b, int c,int* max, int* min);

int main()              //指针用于函数的参数
{
    int bh =3;
    string message = "你是一只傻傻鸟!";

    func(&bh, &message);

    int a = 180, b =170 , c =175, m , n;
    func1(a,b,c,&m,&n);
    cout << "m = " << m << ", n = " << n <<endl;

    // int* no = &bh;
    // string* str = &message;
    // cout << "亲爱的" << *no << "号:" << *str <<endl;

    // *no = 8;
    // *str = "你有一只小小鸟!";
    cout << "亲爱的" << bh << "号:" << message <<endl;
}

void func(int* no, string* str)
{
    cout << "亲爱的" << *no << "号:" << *str <<endl;
    *no = 8;
    *str = "你有一只小小鸟!";
}

void func1(int a, int b, int c,int* max, int* min)
{
    *max = a > b ? a : b;
    *min = a < b ? a : b;
    *max = *max > c ? *max : c;
    *min = *min < c ? *min : c;
}
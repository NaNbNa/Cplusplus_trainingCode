#include <iostream>

using namespace std;        //函数参数的传递

void func (int no, string str);     //表白的内容
int main()
{
    int bh = 3;
    string message = "你是一只傻傻鸟!";

    func(bh, message);

    cout << "亲爱的" << bh << "号:" << message <<endl;
}

void func (int no, string str)
{
    no = 5; str = "你是一只小小鸟!";
    cout << "亲爱的" << no << "号:" << str <<endl;
}
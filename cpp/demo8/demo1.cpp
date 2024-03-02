#include <iostream>

using namespace std;        //函数的默认参数,注意声明和定义的区别

//void func(const string& name ="西施",const string &message); //false,message不可缺默认值

void func(const string& name ="西施",const string &message="我喜欢你!");

int main()
{
    func("你是一只傻傻鸟!");
    func();
}

void func(const string& name, const string &message)
{
    cout << "亲爱的" << name << ": " << message <<endl;
}
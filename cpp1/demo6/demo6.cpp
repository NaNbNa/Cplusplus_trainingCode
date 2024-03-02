#include <iostream>
#include <thread>
#include <string.h>
using namespace std;

template <typename T>
void show(T girl)
{
    cout << "dear " << girl << ", 你是一只傻傻鸟" <<endl; 
}
void print()
{
    cout << "递归中止." << endl;
}

template <typename T, typename ...Args>
void print(T arg,Args... args)
{
    //cout << "参数:" << arg <<endl;
    show(arg);
    //cout << "还有" << sizeof...(args) << " 个参数未展开" <<endl;
    print(args...);
}

template <typename... Args>
void func(const string& str,Args... args)
{
    cout << str << endl;
    print(args...);
    cout << "表白成功" << endl;
}
int main()
{
    //print("金莲",4,"西施");
    //print("冰冰",8,"西施",3);
    func("我是绝世帅哥", "冰冰",8,"西施",3);
}
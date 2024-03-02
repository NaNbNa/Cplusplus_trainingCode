#include <iostream>
using namespace std;    //重载()    :函数对象,具有函数和对象的特点

void show(string name)
{
    cout << "普通函数: " << name <<endl;
}

class cgirl
{
public:
    void operator()(string str)
    {
        cout << "重载函数: " << str <<endl;
    }
};
int main()
{
    show("你是一只傻傻鸟!");

    cgirl g;
    g("你是一只傻傻鸟!");

    cgirl show;
    show("你是一只傻傻鸟!");
    ::show("你是一只傻傻鸟!");
    show("你是一只傻傻鸟!");
}
#include <iostream>

using namespace std;            //引用作为参数,记住:用法看作别名,本质看作指针

void func1(int no, string str)
{
    no =8;
    str = "我是谁";
    cout << "亲爱的" << no << "号 : " << str << endl;
}
void func2 (int* no, string* str)
{
    *no =8;
    *str = "我是谁";
    cout << "亲爱的" << *no << "号 : " << *str << endl;
}

void func3 (int& no, string& str)
{
    no =8;
    str = "我是谁";
    cout << "亲爱的" << no << "号 : " << str << endl;
}


int main()
{
    int bh = 3;
    string str = "你是一直傻傻鸟!";

    //func1(bh, str);
    //func2(&bh, &str);
    func3(bh, str);

     cout << "亲爱的" << bh << "号 : " << str << endl;
}

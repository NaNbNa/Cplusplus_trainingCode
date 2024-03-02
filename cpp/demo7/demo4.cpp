#include <iostream>

using namespace std;            //引用参数和const
                                //const的巨大用处:临时变量
                                //区分左值,非左值和右值;字面常量,字符串常量和数字常量

void func1(int no, string str)
{
    // no =8;
    // str = "我是谁";
    cout << "亲爱的" << no << "号 : " << str << endl;
}
void func2 (int* no, string* str)
{
    // *no =8;
    // *str = "我是谁";
    cout << "亲爱的" << *no << "号 : " << *str << endl;
}

void func3 (int& no,string& str)
{
    // no =8;
    // str = "我是谁";
    cout << "亲爱的" << no << "号 : " << str << endl;
}

void func4 (const int& no,const string& str)  //多了const
{
    // no =8;
    // str = "我是谁";
    cout << "亲爱的" << no << "号 : " << str << endl;
}

void func5 (const int* no,const string* str)
{
    // *no =8;
    // *str = "我是谁";
    cout << "亲爱的" << *no << "号 : " << *str << endl;
}

int main()
{
    int bh = 3;
    string str = "你是一只傻傻鸟!";

    // func1(bh, str);
    // func2(&bh, &str);
    // func3(bh, str);
    func1(8,"你是一只傻傻鸟!");  //ok
    //func2(8,"你是一只傻傻鸟!");  //false,因为要传地址
    //func3(8,"你是一只傻傻鸟!");  //false,本质是指针,要传地址
    func4(9,"你是一只傻傻鸟!");  //ok,在引用中的const的用法:建立临时变量
    //func5(9,"你是一只傻傻鸟!");  //false,const无法在指针处建立临时变量

     cout << "亲爱的" << bh << "号 : " << str << endl;
}

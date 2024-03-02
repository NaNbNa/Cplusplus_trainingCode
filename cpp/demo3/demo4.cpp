#include <iostream>

using namespace std;

int main()              //字符串的用法
{
    string str = "西施";

    str = "美女西施";

    cout << "请输入超女的姓名:";
    cin >> str;

    if (str == "冰冰") cout << "我喜欢你!" <<endl;
    else cout << "我不玩了!" <<endl;

    str = "姓名: " + str + ", 这是我的现女友.";
    cout << str << endl; 

    //+号的错误示范:
    //str = "超女的姓名:" + "冰冰";

    str = "超女的姓名:"  "冰冰";
    cout << "str = " << str <<endl;
}
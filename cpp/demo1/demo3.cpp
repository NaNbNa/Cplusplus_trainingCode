#include <iostream>

using namespace std;

int main() // 熟悉输入操作
{
    // 如果为空如何反应---int输出为，double输出为，
    string name;        // char or not string or int
    int age;            // not int or double
    double weight;      // int or not double
    char sex;           // bigger than 1
    bool beauty ; // >=1 or not true,false

    cout << "超女的颜值：";
    cin >> beauty;
    cout << "已知超女的姓名：" << name << endl
         << "         年龄：" << age << endl
         << "         体重：" << weight << endl
         << "         性别：" << sex << endl
         << "         颜值：" << beauty << endl;
}
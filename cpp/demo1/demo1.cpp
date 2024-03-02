#include <iostream>

using namespace std;

int main()
{
    string name;    //姓名
    int age;        //年龄 
    double weight;  //体重
    char sex;       //性别
    bool beauty;    //颜值

    name = "西施";
    age = 20;
    weight = 48.6;
    sex ='X';
    beauty = true;

    cout << "姓名：" << name << '\n'
         << "年龄：" << age << '\n'
         << "体重：" << weight << '\n'
         << "性别：" << sex << '\n'
         << "颜值：" << beauty << '\n';     //打印出来的不是true，而是1

    name = "冰冰";
    age = 21;
    weight =  48.6;
    sex = 'X';
    beauty = true;
    cout << "姓名：" << name << '\n'
         << "年龄：" << age << '\n'
         << "体重：" << weight << '\n'
         << "性别：" << sex << '\n'
         << "颜值：" << beauty << '\n';
}
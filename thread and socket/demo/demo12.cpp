#include <iostream>
#include <unistd.h>
using namespace std;        //退出方式


struct AA
{
    string name;
    AA(const string & str):name(str){}
    ~AA()
    {
        cout << name << "调用了析构函数" << endl;
    }
};
void func2()
{
    cout << "调用了func2()函数" <<endl;
    //exit(0);
    //return;
}
void func1()
{
    cout << "调用了func1()函数" <<endl;
    //func2();
    //cout << "调用了func1()函数" <<endl;
}

//AA a1("西施1");  //global

int main()
{
    // func1();
    // cout << "回到了main函数" <<endl;
    //return 1;
    //exit(1);

    // AA a2("西施2");
    // //return 0;
    // //exit(0);
    // //_Exit(0);
    // _exit(0);

    atexit(func1);
    atexit(func2);
    //return 0;
    //exit(1);
    _exit(1);
}
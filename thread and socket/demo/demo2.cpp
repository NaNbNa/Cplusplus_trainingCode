#include <iostream>
#include <string.h>
using namespace std;

void show(const char* name1, const char* name2,const char* message)
{
    cout << name1 << "开始表白" <<endl;
    cout << name2 << ": " << message <<endl;
}

int main(int argc ,char* argv[], char* envp[])
{
    if(argc!=4)
    {
        cout << "表白神器的使用方法： ./demo 追求者姓名 被追求者姓名 表白内容" <<endl;
        return -1;
    }
    cout << "表白前的准备工作1" <<endl;
    cout << "表白前的准备工作2" <<endl;

    show(argv[1],argv[2],argv[3]);
    cout << "表白完成" <<endl;

    for(int ii=0;ii<10;ii++)
    {
        string str = "这是第" + to_string(ii) + "个超级女生";
        cout << str <<endl;
    }

    return 0;
}
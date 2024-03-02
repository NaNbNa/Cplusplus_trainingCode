#include <iostream>
#include <unistd.h>
#include <thread>
using namespace std;

void func(int bh,const string& str)
{
    for(int ii=0;ii<10;ii++)
    {
        cout << "第" << ii << "次表白: 亲爱的" << bh <<"号:" << str <<endl;
        sleep(1);
    }
}

int main()
{
    thread t1(func,3,"你是一只傻傻鸟");
    thread t2(func,8,"你有一只小小鸟");

    t1.detach();t2.detach();
    if(t1.joinable()==false)
        cout << "t1分离" <<endl;
    else 
        cout << "t1未分离" <<endl;
    sleep(11);
    // cout <<"任务开始." <<endl;
    // for(int ii=0;ii<12;ii++)
    // {
    //     cout << "执行任务中..." <<endl;
    //     sleep(1);
    // }
    // cout << "任务完成." <<endl;

    //return 0;
    // t1.join();
    // t2.join();
}

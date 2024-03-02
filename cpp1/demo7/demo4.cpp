#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
using namespace std;    //如何多线程下,te'ding'han'su

once_flag onceflag;
void once_func(int bh, const string& str)
{
        cout << bh <<", " << str <<endl;
        //sleep(1);
        this_thread::sleep_for(chrono::seconds(1));
}

void func(int bh, const string& str)
{
    call_once(onceflag,once_func,0,"各位观众,你们要开始表白了.");

    for(int ii=1;ii<=3;ii++)
    {
        cout << "第" << ii << "次表白: 亲爱的" << bh <<"号:" << str <<endl;
        //sleep(1);
        this_thread::sleep_for(chrono::seconds(1));
    }
}
int main()
{
    thread t1(func,3,"你是一只傻傻鸟");
    thread t2(func,8,"你有一只小小鸟");

    t1.join();
    t2.join();
}
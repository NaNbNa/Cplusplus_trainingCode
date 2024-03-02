#include <iostream>
#include <unistd.h>
#include <thread>
using namespace std;        //创建线程

void func(int bh,const string& str)
{
    for(int ii=0;ii<10;ii++)
    {
        cout << "第" << ii << "次表白: 亲爱的" << bh <<"号:" << str <<endl;
        sleep(1);
    }
}

class mythread
{
public: 
    void operator()(int bh,const string& str)
    {
        for(int ii=0;ii<10;ii++)
        {
            cout << "第" << ii << "次表白: 亲爱的" << bh <<"号:" << str <<endl;
            sleep(1);
        }
    }
};

class mythread1
{
public: 
    static void func(int bh,const string& str)
    {
        for(int ii=0;ii<10;ii++)
        {
            cout << "第" << ii << "次表白: 亲爱的" << bh <<"号:" << str <<endl;
            sleep(1);
        }
    }
};

class mythread2
{
public: 
    void func(int bh,const string& str)
    {
        for(int ii=0;ii<10;ii++)
        {
            cout << "第" << ii << "次表白: 亲爱的" << bh <<"号:" << str <<endl;
            sleep(1);
        }
    }
};

int main()
{
    // thread t1(func,3,"你是一只傻傻鸟");
    // thread t2(func,8,"你有一只小小鸟");

    auto f = [](int bh,const string& str)
    {
        for(int ii=0;ii<10;ii++)
        {
            cout << "第" << ii << "次表白: 亲爱的" << bh <<"号:" << str <<endl;
            sleep(1);
        }
    };

    //thread t3(f,4,"你有一只傻傻鸟");

    //thread t4(mythread(),3,"你是一只傻傻鸟");

    //thread t5(mythread1::func,3,"你是一只傻傻鸟");    //类静态成员函数

    mythread2 myth;                 //类的普通成员函数
    thread t6(&mythread2::func,&myth,3,"你是一只傻傻鸟");

    cout <<"任务开始." <<endl;
    for(int ii=0;ii<10;ii++)
    {
        cout << "执行任务中..." <<endl;
        sleep(1);
    }
    cout << "任务完成." <<endl;

    // t1.join();
    // t2.join();
    //t3.join();
    //t4.join();
    //t5.join();
    t6.join();
}

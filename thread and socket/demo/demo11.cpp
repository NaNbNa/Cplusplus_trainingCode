#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;    //linux的信号处理

void func(int signum)
{
    cout << "收到了信号： " << signum <<endl;
    signal(signum,SIG_DFL);
}

void func1(int sig)
{
    cout << "闹钟响了，执行定时任务" <<endl;
    //alarm(3);
}

void EXIT(int sig)
{
    cout << "收到信号：" << sig <<endl;
    cout << "释放资源, 程序逐渐退出" <<endl;

    cout << "程序退出" <<endl;
    exit(0);
}
int main(int argc, char* argv[])
{   
    // signal(1,func);
    // signal(15,func);
    // signal(2,func);
    // signal(9,SIG_IGN);
 
    // alarm(3);
    // signal(14,func1);

    // int ii =0;
    // while(true)
    // {
    //     ii++;
    //     cout << "执行了"<< ii << "次任务" <<endl;
    //     sleep(1);
    // }

    for(int ii=1;ii<=64;ii++) signal(ii,SIG_IGN);

    signal(2,EXIT); signal(15,EXIT);

    int ii =0;
    while(true)
    {
        ii++;
        cout << "执行了"<< ii << "次任务" <<endl;
        sleep(1);
    }
}
#include <iostream>
#include <unistd.h>
#include <signal.h>

using namespace std;    //多进程与信号:处理父子进程的终止，资源处理

void FathEXIT(int sig);
void ChldEXIT(int sig);

int main()
{
    for(int ii=1;ii<=64;ii++) signal(ii,SIG_IGN);   //同时也避免了僵尸进程

    signal(SIGTERM,FathEXIT);signal(SIGINT,FathEXIT);

    while(true)
    {
        if(fork()>0)
        {
            sleep(3);continue;
        }
        else
        {
            signal(SIGTERM,ChldEXIT);
            signal(SIGINT,SIG_IGN);

            while(true)
            {
                cout << "子线程" << getpid() << "正在运行中" <<endl;
                sleep(3);
            }
        }
    }
}

void FathEXIT(int sig)
{
    signal(SIGINT,SIG_IGN);signal(SIGTERM,SIG_IGN);

    cout << "父进程退出" << getpid() <<  ", sig=" << sig <<endl;
    kill(0,SIGTERM);
    //处理资源
    exit(0);
}

void ChldEXIT(int sig)
{
    signal(SIGINT,SIG_IGN);signal(SIGTERM,SIG_IGN);

    cout << "子进程" << getpid() << "退出, sig=" << sig <<endl;
    //释放资源
    exit(0); 
}

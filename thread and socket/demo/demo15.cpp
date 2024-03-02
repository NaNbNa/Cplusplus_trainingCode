#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;    //僵尸进程

void func(int sig)
{
    int sts;

    pid_t pid = wait(&sts);

    cout << "已中止的子进程的编号是： " << pid <<endl;

    if(WIFEXITED(sts)==true)
    { cout << "子进程是正常退出的，退出状态是： " << WEXITSTATUS(sts) <<endl;}
    else
    { cout << "子进程是异常退出的，终止它的信号是： " << WTERMSIG(sts) <<endl; }

}

int main()
{
    // if(fork()>0)
    // {
    //     sleep(10);
    //     cout << "父进程将退出" <<endl;
    //     return 0;
    // }
    // else{
    //     for(int ii=0;ii<100;ii++)
    //     {
    //         cout << "子进程继续运行中..." << ii  <<endl;
    //         sleep(1);
    //     }
    // }

//     signal(SIGCHLD,SIG_IGN);

//     if(fork()==0) return 0;

//     while(true)
//     {
//         cout << "父进程服务进行中。。。" <<endl;
//         sleep(1);
//     }

    signal(SIGCHLD,func);
    if(fork()>0)
    {
        while(true)
        {
            sleep(1);
            cout << "父进程进行中。。。" <<endl;
        }
    }
    else
    {
        sleep(5);
        int *p =nullptr; *p =8;
        exit(1);
    }
}
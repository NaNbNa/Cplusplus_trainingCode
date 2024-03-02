#include <iostream>
#include <unistd.h>
#include <fstream>
using namespace std;    //创建子进程--父子差别
                        //system的本质

int main()
{
    // int bh=8;
    // string message = "你是一只傻傻鸟";

    // pid_t pid = fork();

    // // cout << "亲爱的" << bh << "号: " << message <<endl;
    // // //sleep(20);
    // // cout << "程序结束" <<endl;
    // if(pid>0)
    // {    
    //     sleep(1);
    //     cout << "pid=" << pid <<endl;
    //     cout << "父进程" <<endl;
    //     //cout << "父: 亲爱的" << &bh << "号: " << &message <<endl;
    //     cout << "父: 亲爱的" << bh << "号: " << message <<endl;
    // }
    // else
    // {
    //     bh=3;
    //     message = "你是一只傻傻鸟";
    //     cout << "pid=" << pid <<endl;
    //     cout << "子进程" <<endl;
    //     //cout << "子: 亲爱的" << &bh << "号: " << &message <<endl;
    //     cout << "子: 亲爱的" << bh << "号: " << message <<endl;
    // }

    // if (fork()>0)
    // {
    //     while(true)
    //     {
    //         sleep(1);
    //         cout << "父进程运行中。。。" <<endl;
    //     }
    // }
    // else 
    // {
    //     sleep(10);
    //     cout << "子进程运行中。。。" <<endl;
    //     execl("/bin/ls","/bin/ls","-lt","/tmp",0);
    //     cout << "子进程运行结束" <<endl;
    // }

    ofstream fout;
    fout.open("/tmp/tmp.txt");

    fork();

    for(int ii=0;ii<10000;ii++)
    {
        fout << "进程" << getpid() << "西施" << ii << "极漂亮" <<endl;
    }

    fout.close();
}
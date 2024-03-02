#include <iostream>
#include <unistd.h>
#include <string.h>
using namespace std;    // 调用可执行程序/命令

int main(int argc,char* argv[])
{
    // int ret = system("/bin/l1s -l /tmp");
    // cout << "ret=" << ret <<endl;
    // perror("system");

    // cout << "demo13.cpp 本进程编号是：" << getpid() <<endl;
    // int ret = execl("/root/work1/demo/demo1", "/root/work1/demo/demo1",0);
    // //int ret = system("/root/work1/demo/demo1");

    // cout << "ret=" <<ret <<endl;
    // perror("execl");

    //cout << "execv" <<endl;
    char* args[10];
    args[0] = const_cast<char*>("/bin/ls");
    args[1] = const_cast<char*>("-lt");
    args[2] = const_cast<char*>("/tmp");
    args[3] = 0;
    
    int ret = execv("/bin/ls",args);
    cout << "ret=" << ret <<endl;
    perror("exev");
}
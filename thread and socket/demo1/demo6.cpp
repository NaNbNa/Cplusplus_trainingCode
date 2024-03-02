#include "server.h"

void FathEXIT(int sig);
void ChldEXIT(int sig);

cTcpServer listenfd;

int main(int argc,char* argv[])     //模拟服务端
{
    if(argc!=2)
    {
        cout << "Using: ./demo6 774" <<endl;
        return -1;
    }

    for(int ii=1;ii<=64;ii++) signal(ii,SIG_IGN);       //信号
    signal(SIGTERM,FathEXIT);signal(SIGINT,FathEXIT);  //15, 2

   
    
    if(listenfd.initserver(atoi(argv[1]))==false)
    {
        perror("initserver");return -1;
    } 

    while(true)
    {
        if(listenfd.accept()==false)   //受理一个客户端连接,并创建一个子进程处理
        {
            perror("accept");return -1;
        }

        int pid = fork();
        if(pid==-1) {perror("fork");return -1;}
        if(pid>0) 
        {
            listenfd.closeclient();
            continue;
        }   //父进程继续受理,子进程进行处理
        
        listenfd.closelisten();
        signal(SIGTERM,ChldEXIT);signal(SIGINT,SIG_IGN);    //子进程信号

        cout << "客户端(" <<  listenfd.clientip() << ")已连接" <<endl; 
        string buffer;
        cout << "服务子进程pid=" << getpid() <<endl;
        while(true)
        {
            if(listenfd.recv(buffer,1024)==false)
            {
                cout << "客户端断开连接: ";
                perror("recv()");break; 
            }
            cout <<  "接受: " << buffer <<endl;

            buffer = "服务子进程" + to_string(getpid()) + ": ok";
            if(listenfd.send(buffer)==false)
            {
                perror("send()");break;
            }
            cout << "发送: " << buffer <<endl;
        }

        return 0;
    }
}

void FathEXIT(int sig)
{
    signal(SIGTERM,SIG_IGN);signal(SIGINT,SIG_IGN);

    cout << "父进程" << getpid() << ": 退出,sig=" << sig <<endl;

    listenfd.closelisten();

    kill(0,SIGTERM);
    exit(0);
}

void ChldEXIT(int sig)
{
    signal(SIGTERM,SIG_IGN);signal(SIGINT,SIG_IGN);
    cout << "子进程" << getpid() << ": 退出,sig=" << sig <<endl;

    listenfd.closeclient();
    
    exit(0);
}
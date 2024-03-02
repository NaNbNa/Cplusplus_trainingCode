#include "server.h"

void FathEXIT(int sig);
void ChldEXIT(int sig);

cTcpServer listenfd;

int main(int argc,char *argv[])     //模拟服务端，接受文件
{
    if(argc!=3)
    {
        cout << "Using: ./demo8 774 /tmp" <<endl;return -1;
    }

    for(int ii=1;ii<=64;ii++) signal(ii,SIG_IGN);
    signal(SIGTERM,FathEXIT);signal(SIGINT,FathEXIT);

    if(listenfd.initserver(atoi(argv[1]))==false)
    {
        perror("initserver()"); return -1;
    }

    while(true)
    {
        if(listenfd.accept()==false)
        {
            perror("accept"); return -1;
        }

        int pid = fork();
        if(pid==-1) {perror("fork()"); return -1;}
        if(pid>0)
        {
            listenfd.closeclient();
            continue;
        }
        
        signal(SIGTERM,ChldEXIT);signal(SIGINT,SIG_IGN);    //不需要捕获2
        listenfd.closelisten();

        cout << "客户端(" <<  listenfd.clientip() << ")已连接" <<endl; 
        
        struct st_file
        {
            char filename[256];
            int filesize;
        }fileinfo;

        if(listenfd.recv(&fileinfo,sizeof(fileinfo))==false) {perror("recv()");return -1;}
        cout << "文件信息结构体:" << fileinfo.filename << "(" << fileinfo.filesize << ")" <<endl;
        if(listenfd.send("ok")==false) {perror("send()");return -1;}

        if(listenfd.recvfile(string(argv[2])+"/"+fileinfo.filename,fileinfo.filesize)==false)
        {
            perror("recvfile()");return -1;
        }
        cout << "接受文件内容成功" <<endl; 

        if(listenfd.send("ok")==false) {perror("send()");return -1;}

        return 0;
    }
}

void FathEXIT(int sig)
{
    signal(SIGTERM,SIG_IGN);signal(SIGINT,SIG_IGN);

    cout << "父进程" << getpid() << "退出, sig=" << sig <<endl;

    listenfd.closelisten();

    kill(0,SIGTERM);
    exit(0);
}
void ChldEXIT(int sig)
{ 
    signal(SIGTERM,SIG_IGN);signal(SIGINT,SIG_IGN);

    cout << "子进程" << getpid() << "退出, sig=" << endl;

    listenfd.closeclient();
    exit(0);
}
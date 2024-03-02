#include "server.h"

int main(int argc,char *argv[]) //模拟客户端传输文件
{
    if(argc!=5)
    {
        cout << "Using: ./demo7 123.60.94.223 774 data.txt  1362" <<endl;return -1;
    }

    cTcpClient client;
    if(client.connect(argv[1],atoi(argv[2]))==false)
    {
        perror("connect()"); return -1;
    }
    
    struct st_file
    {
        char filename[256];
        int filesize;
    }fileinfo;
    memset(&fileinfo,0,sizeof(fileinfo));
    strcpy(fileinfo.filename,argv[3]);
    fileinfo.filesize = atoi(argv[4]);

    if(client.send(&fileinfo,sizeof(fileinfo))==false) {perror("send()"); return -1;}
    cout << "发送了文件信息结构体: " << fileinfo.filename << "(" << fileinfo.filesize <<")" <<endl;
    
    string buffer;
    if(client.recv(buffer,2)==false) {perror("recv()");return -1;}
    if(buffer!="ok") {cout << "服务器没有回复ok"<<endl; return -1;}

    if(client.sendfile(fileinfo.filename,fileinfo.filesize)==false) 
    {
        perror("sendfile()");return -1;
    }
    
    if(client.recv(buffer,2)==false) {perror("recv()");return -1;}
    if(buffer!="ok") {cout << "发送文件内容失败" <<endl;return -1;} 
    cout << "发送文件内容成功" <<endl;
}   
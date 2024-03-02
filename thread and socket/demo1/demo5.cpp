#include "server.h"

int main(int argc,char* argv[]) //客户端
{
    if(argc!=3)
    {
        cout << "Using: ./demo5 服务器端的IP 服务器端的端口" <<endl;
        cout << "Example: ./demo5 123.60.94.223 774" <<endl <<endl;
        return -1;
    }

    cTcpClient client;
    if((client.connect(argv[1],atoi(argv[2])))==false)
    {
        perror("connect");return -1;
    }

    
    string buffer;
    for(int ii=1;ii<=10;ii++)
    {
        buffer = "客户端进程" + to_string(getpid())+ ": 这是第" + to_string(ii) + "个超级女生, 编号:" + to_string(ii); 
        if(client.send(buffer)==false)
        {
            perror("send()");break;
        }
        cout << "发送: " << buffer <<endl;
        if(client.recv(buffer,1024)==false)
        {
            perror("recv()");break;
        }
        cout << "接受: " << buffer <<endl;
        sleep(1);
    }
}
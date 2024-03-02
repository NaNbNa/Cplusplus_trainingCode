#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
using namespace std;

int main(int argc,char* argv[])        //模拟客户端
{
    if(argc!=3)
    {
        cout << "Using: ./demo2 服务器端的IP 服务器端的端口" <<endl;
        cout << "Example: ./demo2 123.60.94.223 774" <<endl <<endl;
        return -1;
    }

    int sockfd = socket(AF_INET,SOCK_STREAM,0);         //1\

    // while(true)
    // {
    //     sockfd = socket(AF_INET,SOCK_STREAM,0);  
    //     cout << "sockfd=" << sockfd <<endl;
    //     if(sockfd==-1)
    //     {
    //         perror("socket creation failed"); // 打印错误信息  
    //         return -1; // 返回错误代码  
    //     }
    // }

    if(sockfd==-1)
    {
        perror("socket creation failed"); // 打印错误信息  
        return -1; // 返回错误代码  
    }


    struct hostent* h;                                  //2
    if( (h = gethostbyname(argv[1]))==0)        //argv[1]
    {
        cout << "gethostbyname failed" <<endl;
        close(sockfd); return -1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));   
    servaddr.sin_family = AF_INET;
    memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);
    //memcpy(&servaddr.sin_addr,h->h_addr_list,h->h_length); //false，这使得无法连接
    //memcpy(&servaddr.sin_addr,h->h_addr_list[0],h->h_length); //true
    servaddr.sin_port = htons(atoi(argv[2]));    //argv[2]

    if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) !=0)
    {
        perror("connect");return -1;
    }

    int buffsize =0;
    socklen_t optlen = sizeof(buffsize);
    getsockopt(sockfd,SOL_SOCKET,SO_SNDBUF,&buffsize,&optlen);
    cout << "send buffsize=" << buffsize <<endl;
    getsockopt(sockfd,SOL_SOCKET,SO_RCVBUF,&buffsize,&optlen);
    cout << "recv buffsize=" << buffsize <<endl;

    char buffer[1024];                                  //3
    for(int ii=0;ii<3;ii++)
    {
        int iret;
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"这是第%d个超级女生,编号%03d.",ii+1,ii+1);
        //if( (iret=send(sockfd,buffer,strlen(buffer),0))<=0)
        if( (iret=write(sockfd,buffer,strlen(buffer)))<=0)
        {
            perror("send");break;
        }
        cout << "发送:" << buffer <<endl;

        memset(buffer,0,sizeof(buffer));

        //if( (iret=recv(sockfd,buffer,sizeof(buffer),0))<=0)
        if( (iret=read(sockfd,buffer,sizeof(buffer)))<=0)
        {
            cout << "iret=" << iret <<endl; break;
        }
        cout << "接受" << buffer <<endl;
        sleep(1);
    }

    close(sockfd);                                      //4

}
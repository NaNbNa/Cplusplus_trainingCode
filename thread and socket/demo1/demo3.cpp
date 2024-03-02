#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "sys/socket.h"

using namespace std;    //文件描述符---输入-0，输出-1，error-2

int main()
{
    // close(0);
    // close(1);
    // close(2);
    // int ii=0;
    // cin >> ii;
    // cout << "cout ii=" << ii <<endl;
    // cerr << "cerr ii=" << ii <<endl;
    // sleep(100);
    // return  0;

    int fd;
    char buffer[1024];
    memset(buffer,0,sizeof(buffer));

    fd = open("data.txt",O_CREAT|O_RDWR|O_TRUNC);
    if(fd==-1)
    {
        perror("open(data.txt)");return -1;
    }
    printf("文件描述符fd=%d\n",fd);

    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    printf("sockfd=%d\n", sockfd);

    strcpy(buffer,"你是一只傻傻鸟\n");

    if(write(fd,buffer,strlen(buffer))==-1)
    {
        perror("write()");return -1;
    }
    

    sleep(100);
    close(fd);
}

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    fd = open("data.txt",O_RDONLY);
    if(fd==-1)
    {
        perror("open(data.txt)"); return -1;
    }

    printf("文件描述符fd=%d\n",fd);

    char buffer[1024];
    memset(buffer,0,sizeof(buffer));
    if(read(fd,buffer,sizeof(buffer))==-1)
    {   
        perror("read()"); return -1;
    }
    
    printf("%s",buffer);


    close(fd);
}
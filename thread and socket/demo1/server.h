#ifndef SERVER
#define SERVER 1

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <signal.h>
#include <fstream>
using namespace std;

class cTcpServer
{
private:
    int m_listenfd;
    int m_clientfd;
    string m_clientip;
    unsigned short m_port;
public:
    cTcpServer();
    
    bool initserver(unsigned short);
    string clientip();
    bool accept();
    bool recv(string&,const size_t);
    bool recv(void*,const size_t);
    bool recvfile(const string&,const size_t);
    bool send(const string&);
    bool closeclient();
    bool closelisten();
    ~cTcpServer();
};

class cTcpClient
{
private:
    int m_clientfd;
    string m_ip;
    unsigned short m_port;
public:
    cTcpClient();
    bool connect(const string&,const unsigned short);
    bool send(const string&);
    bool send(const void*,const size_t);
    bool sendfile(const string&,const size_t);
    bool recv(string&,const size_t);
    bool close();
    ~cTcpClient();
};

#endif
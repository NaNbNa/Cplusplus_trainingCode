#include "server.h"

cTcpServer::cTcpServer():m_listenfd(-1),m_clientfd(-1){}

bool cTcpServer::initserver(unsigned short in_port)
{
    if(m_listenfd!=-1) return false;

    m_port = in_port;

    if((m_listenfd = socket(AF_INET,SOCK_STREAM,0))==-1) return false;

    //避免服务器进入TIME_WAIT后socket重用失败----------------------------
    int opt =1;
    setsockopt(m_listenfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(in_port);

    if(::bind(m_listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr))!=0)
    {
        ::close(m_listenfd);m_listenfd =-1;return false;
    }

    if(listen(m_listenfd,5)!=0)
    {
        ::close(m_listenfd);m_listenfd =-1; return false;
    }

    return true;
}


string cTcpServer::clientip()
{
    return m_clientip;
}

bool cTcpServer::accept()
{
    if(m_listenfd==-1)  return false;

    struct sockaddr_in caddr;
    socklen_t addrlen = sizeof(caddr);

    if((m_clientfd=::accept(m_listenfd,(struct sockaddr*)&caddr,&addrlen))==-1) return false;

    m_clientip = inet_ntoa(caddr.sin_addr);
    return true;
}   
//接收数据与发送数据不同，不需要判断两端是否连接，因为有缓冲区
bool cTcpServer::recv(string& buffer,const size_t maxlen)
{
    buffer.clear();buffer.resize(maxlen);
    int readn = ::recv(m_clientfd,&buffer[0],buffer.size(),0);
    if(readn<=0) return false;

    buffer.resize(readn);
    return true;
}
//接收数据与发送数据不同，不需要判断两端是否连接，因为有缓冲区
bool cTcpServer::recv(void* buffer,const size_t size)
{
    memset(buffer,0,size);
    int readn = ::recv(m_clientfd,buffer,size,0);
    if(readn<=0) return false;

    return true;
}
//接收数据与发送数据不同，不需要判断两端是否连接，因为有缓冲区
bool cTcpServer::recvfile(const string& filename,const size_t filesize)
{
    ofstream fout;
    fout.open(filename,ios::binary);
    if(fout.is_open()==false) { cout << "打开文件" << filename << "失败" <<endl;return false;}
    int onread =0;
    int totalbytes =0;
    char buffer[4096];

    while(true)
    {
        memset(buffer, 0 ,sizeof(buffer));

        if(filesize - totalbytes>4096) onread =4096;
        else onread = filesize - totalbytes;

        if(recv(buffer,onread)==false) return false;

        fout.write(buffer,onread);

        totalbytes = totalbytes + onread;

        if(totalbytes==filesize) break;
    }
    return true;
}
bool cTcpServer::send(const string& buffer)
{
    if(m_clientfd==-1) return  false;

    if(::send(m_clientfd,buffer.data(),buffer.size(),0)<=0) return false;

    return true;
}


bool cTcpServer::closelisten()
{
    if(m_listenfd==-1) return false;

    ::close(m_listenfd);
    m_listenfd =-1;
    return true;
}
bool cTcpServer::closeclient()
{
    if(m_clientfd==-1) return false;

    ::close(m_clientfd);
    m_clientfd = -1;
    return true;
}
cTcpServer::~cTcpServer()
{
    closelisten();closeclient();
}

// -------------------------------------客户端

cTcpClient::cTcpClient():m_clientfd(-1){}

bool cTcpClient::connect(const string& in_ip,const unsigned short in_port)
{
    if(m_clientfd!=-1) return false;

    m_ip =in_ip;m_port = in_port;

    if((m_clientfd = socket(AF_INET,SOCK_STREAM,0))==-1) return false;

    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(in_port);

    struct hostent* h;
    if((h = gethostbyname(m_ip.c_str()))==nullptr)
    {
        ::close(m_clientfd);m_clientfd =-1; return false;
    }
    memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);

    //重名处理，多加 ::
    if(::connect(m_clientfd,(struct sockaddr*)&servaddr,sizeof(servaddr))==-1)  
    {
        ::close(m_clientfd),m_clientfd =-1; return false;
    }
    return true;
}
bool cTcpClient::send(const string& buffer)
{
    if(m_clientfd==-1) return false;

    if(::send(m_clientfd,buffer.data(),buffer.size(),0)<=0) return false;

    return true;
}

bool cTcpClient::send(const void* buffer,const size_t size)
{
    if(m_clientfd==-1) return false;
    if(::send(m_clientfd,buffer,size,0)<=0) return false;

    return true;
}

bool cTcpClient::sendfile(const string& filename,const size_t filesize)
{
    ifstream fin(filename,ios::binary);

    int onread=0;
    int totalbytes = 0;
    char buffer[4096];
    while(true)
    {
        memset(buffer,0,sizeof(buffer));

        if(filesize-totalbytes>4096) onread = 4096;
        else onread = filesize - totalbytes;

        fin.read(buffer,onread);

        if(send(buffer,onread)==false) return false;

        totalbytes = totalbytes + onread;

        if(totalbytes==filesize) break; 
    }    
    return true;
}

//接收数据与发送数据不同，不需要判断两端是否连接，因为有缓冲区
bool cTcpClient::recv(string& buffer,const size_t maxlen)
{
    buffer.clear();
    buffer.resize(maxlen);
    int readn = ::recv(m_clientfd,&buffer[0],buffer.size(),0);
    if(readn<=0) 
    {
        buffer.clear();return false;
    }
    buffer.resize(readn);
    return true;
}
bool cTcpClient::close()
{
    if(m_clientfd==-1) return false;
    
    ::close(m_clientfd);
    m_clientfd=-1;
    return true;
}
cTcpClient::~cTcpClient(){close();}


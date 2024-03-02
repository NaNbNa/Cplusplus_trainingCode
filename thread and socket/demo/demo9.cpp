#include <iostream>
#include <cstring>
#include <cerrno>
#include <sys/stat.h>

using namespace std;  //Linux的系统错误
int main()
{
//  int ii;

  //for(int ii=0;ii<150;ii++)
  {
   // cout << ii << ":" << strerror(ii) <<endl;
  }
  
  int iret = mkdir("/temp/aaa", 0755);
  if (iret !=0)
  {
  cout << "iret=" << iret <<endl;
  cout << errno << ":" << strerror(errno) <<endl;
  perror("调用mkdir（/temp/aaa)失败");
  }

  iret = mkdir("/tmp/aaa", 0755);
  if( iret !=0)
  {
  cout << "iret=" << iret <<endl;
  cout << errno << ":" << strerror(errno) <<endl;
  perror("调用mkdir（/tmp/aaa)失败");
  }
}

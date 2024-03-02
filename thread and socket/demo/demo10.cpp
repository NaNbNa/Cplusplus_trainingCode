#include <iostream>
#include <cstdio>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
using namespace std;

int main(int argc, char* argv[])
{
  if (argc!=2) {cout << "Using: ./demo 文件或者目录名" <<endl; return -1;}

//  if (access(argv[1], F_OK) != 0)
  {
//     cout << "文件或目录" << argv[1] << "不存在" << endl; return -1;
  }

//  cout << "文件或目录" << argv[1] << "已存在" <<endl;
  
  struct stat st;
  
  if (stat(argv[1],&st)!=0)
  {
    cout << "stat(" << argv[1] << "):" << strerror(errno) <<endl; return -1;
  }
  
  if ( S_ISREG(st.st_mode))
     cout <<  argv[1] << "是一个文件(" << "mtime=" << st.st_mtime << ", size=" << st.st_size << ")" <<endl;
  if ( S_ISDIR(st.st_mode))
     cout <<  argv[1] << "是一个目录(" << "mtime=" << st.st_mtime << ", size=" << st.st_size << ")" <<endl;
  return 0;
  
}

#include <iostream>
#include <dirent.h>
using namespace std;  //读取目录列表

int main(int argc, char* argv[])
{
  if(argc!=2) 
  {
    cout << "Using ./demo 目录名" <<endl;
    return -1;
  }

  DIR *dir;

  if ( (dir=opendir(argv[1])) == 0 ) return -1;

  struct dirent* stdinfo = nullptr;

  while(true)
  {
    if ((stdinfo = readdir(dir)) ==0) break;
    
    cout << "文件名=" << stdinfo->d_name << ", 文件类型=" << (int)stdinfo->d_type <<endl;
  }

  closedir(dir);
}

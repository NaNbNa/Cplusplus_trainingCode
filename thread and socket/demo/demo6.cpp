#include <iostream>
#include <sys/time.h>
using namespace std;

int main()
{
  timeval start,end;

  gettimeofday(&start,0);

  for(int ii=0;ii<1000000000;ii++);

  gettimeofday(&end,0);

  timeval tv;
  tv.tv_usec= end.tv_usec - start.tv_usec;
  tv.tv_sec = end.tv_sec - start.tv_sec;

  cout << "start.tv_sec=" << start.tv_sec << ", tv_usec=" << start.tv_usec <<endl;
  cout << "end.tv_sec=" << end.tv_sec << ", tv_usec=" << end.tv_usec <<endl;  

  if(tv.tv_usec<0)
  {
    tv.tv_usec = 1000000 + end.tv_usec - start.tv_usec;
    tv.tv_sec--;
  }

  cout << "耗时： " << tv.tv_sec << "秒和" << tv.tv_usec << "微秒" <<endl;
  return 0;
}

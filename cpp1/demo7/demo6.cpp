#include <iostream>
#include <unistd.h>
#include <thread>
using namespace std;        //线程安全--顺序性,可见性,原子性
                            //volatile的功能

volatile int aa =0;

void func()
{
   for(int ii =1;ii<=1000000;ii++)
        aa++;
}



int main()
{
    // func();
    // func();
    thread t1(func);
    thread t2(func);

    t1.join();
    t2.join();
    cout << "aa=" << aa <<endl;
}

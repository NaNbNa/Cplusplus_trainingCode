#include <iostream>
#include <thread>
#include <string.h>
#include <unistd.h>
using namespace std;

int main()
{
    cout << "demo.cpp 本进程编号是：" << getpid() <<endl;
}
#include <iostream>
#include <thread>
#include <pthread.h>

using namespace std;    //native_handle()用法

void func()
{
    for(int ii=1;ii<=10;ii++)
    {
        cout << "ii=" << ii <<endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main()
{
    thread tt(func);

    this_thread::sleep_for(chrono::seconds(3));
    pthread_t thid = tt.native_handle();

    pthread_cancel(thid);       
    tt.join();
}
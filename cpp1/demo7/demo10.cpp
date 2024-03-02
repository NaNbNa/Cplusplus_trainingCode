#include <iostream>
#include <mutex>
#include <thread>
#include <atomic>
using namespace std;    //原子类

atomic<int> aa(10);
void func()
{
    for(int ii=1;ii<=1000000;ii++)
        aa++;
}
int main()
{
    // thread t1(func);
    // thread t2(func);

    // t1.join();
    // t2.join();
    // cout << "aa=" << aa <<endl;

    // atomic<int> a(3);
    // cout << "a=" << a.load() <<endl;
    // cout << "a=" << a <<endl;

    // //a.store(8);
    // a=8;
    // cout << "a=" << a <<endl;

    // int old = a.fetch_add(5);
    // cout << "old=" << old <<", a=" << a<<endl;
    // old = a.fetch_sub(2);
    // cout << "old=" << old <<", a=" << a<<endl;

    atomic<int> ii(3);
    //int expect = 3;
    int expect = 4;
    int val =5;

    bool bret = ii.compare_exchange_strong(expect,val); //CAS指令
    cout << "bret=" << bret <<endl;
    cout << "ii=" << ii <<endl;
    cout << "expect=" << expect <<endl;
}
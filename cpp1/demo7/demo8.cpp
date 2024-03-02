#include <iostream>
#include <thread>
#include <mutex>

using namespace std;        //递归互斥锁的应用场景和lock_guard<mutex>的使用
class AA
{
    //mutex m_mutex;
    recursive_mutex m_mutex;
public:
    void func1()
    {
        m_mutex.lock();
        cout << "func1()" <<endl;
        m_mutex.unlock();
    }

    void func2()
    {
        m_mutex.lock();
        cout << "func2()" <<endl;
        func1();                    //*****
        m_mutex.unlock();
    }
};

int aa = 0;
mutex mtx;
void func()
{
    lock_guard<mutex> mlock(mtx);   //lock_guard<mutex> --类构造和析构+锁

    for(int ii =1;ii<=1000000;ii++)
            aa++;
}

int main()
{
    // AA aa;
    // //aa.func1();
    // aa.func2();

    thread t1(func);
    thread t2(func);

    t1.join();
    t2.join();
    cout << "aa=" << aa <<endl;
}
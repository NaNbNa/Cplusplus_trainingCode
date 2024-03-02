#include <iostream>
#include <mutex>
#include <thread>

using namespace std;        //互斥锁--简单加锁,释放锁

mutex mtx;

int aa =0;

void func1()
{
   for(int ii =1;ii<=1000000;ii++)
   {
    cout << "线程-" <<  this_thread::get_id() << "申请加锁" <<endl;

    mtx.lock();
    aa++;
    this_thread::sleep_for(chrono::seconds(5));         //3
    mtx.unlock();

    cout << "线程-" <<  this_thread::get_id() << "释放了锁" <<endl;
    this_thread::sleep_for(chrono::seconds(1));     //1
   }
}

void func(int bh,const string& str)
{
    for(int ii=0;ii<10;ii++)
    {
        
        mtx.lock();
        cout << "第" << ii << "次表白: 亲爱的" << bh <<"号:" << str <<endl;
        mtx.unlock();
        
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main()
{
    // thread t1(func,1,"你是一只傻傻鸟");
    // thread t2(func,2,"你是一只傻傻鸟");
    // thread t3(func,3,"你是一只傻傻鸟");
    // thread t4(func,4,"你是一只傻傻鸟");
    // thread t5(func,5,"你是一只傻傻鸟");
    // thread t6(func,6,"你是一只傻傻鸟");
    // thread t7(func,7,"你是一只傻傻鸟");
    // thread t8(func,8,"你是一只傻傻鸟");
    // thread t9(func,9,"你是一只傻傻鸟");
    // thread t10(func,10,"你是一只傻傻鸟");

    // t1.join();
    // t2.join();
    // t3.join();
    // t4.join();
    // t5.join();
    // t6.join();
    // t7.join();
    // t8.join();
    // t9.join();
    // t10.join();

    thread t1(func1);
    thread t2(func1);

    
    t1.join();
    t2.join();
    cout << "aa=" << aa << endl;
}
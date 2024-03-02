#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;    //线程id和this_thread

void func(int bh, const string& str)
{
    cout << "子线程:"<< this_thread::get_id() << endl;
    for(int ii=1;ii<=3;ii++)
    {
        cout << "第" << ii << "次表白: 亲爱的" << bh <<"号:" << str <<endl;
        //sleep(1);
        this_thread::sleep_for(chrono::seconds(1));
    }
}
int main()
{
    thread t1(func,3,"你是一只傻傻鸟");
    thread t2(func,8,"你有一只小小鸟");

    cout << "主线程:" <<this_thread::get_id() << endl;
    cout << "子线程t1:" <<t1.get_id() << endl;
    cout << "子线程t2:" <<t2.get_id() << endl;
    t1.swap(t2);
    cout << "子线程t1:" <<t1.get_id() << endl;
    cout << "子线程t2:" <<t2.get_id() << endl;

    //thread t3 = t2; //false
    //thread t3(t2);  //false
    thread t3 = move(t2);
    cout << "子线程t2:" <<t2.get_id() << endl;
    cout << "子线程t3:" <<t3.get_id() << endl;
    t1.join();
    //t2.join();
    t3.join();
}
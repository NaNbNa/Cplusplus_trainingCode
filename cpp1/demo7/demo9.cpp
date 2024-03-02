#include <iostream>
#include <string.h>
#include <thread>
#include <mutex>
#include <deque>
#include <queue>
#include <condition_variable>

using namespace std;        //重点:wait的实际步骤
                            //wait需要和unique_lock搭配,因为wait定义里使用了unique_lock
                            //虚假唤醒
class AA
{
    mutex m_mutex;
    condition_variable m_cond;
    queue<string,deque<string>> m_q;
public:
    void incache(int num)   //生产者
    {
        lock_guard<mutex> lock(m_mutex);
        for(int ii=0;ii<num;ii++)
        {
            static int bh =1;
            string message = to_string(bh++) + "号超女";
            m_q.push(message);
        }
        //m_cond.notify_one();
        m_cond.notify_all();
    }

    void outcache()     //消费者
    {
        string message;

        while(true)
        {
            {           //作用域对锁的效果
                //cout << "线程" << this_thread::get_id() << ", 申请加锁"  <<endl;
                unique_lock<mutex> lock(m_mutex);
                //cout << "线程" << this_thread::get_id() << ", 加锁成功"  <<endl;

                //this_thread::sleep_for(chrono::hours(1));
                while(m_q.empty()==true)    //while循环避免虚假唤醒
                {
                    m_cond.wait(lock);
                    cout << "线程" << this_thread::get_id() << ", 被唤醒"  <<endl;
                }

                message = m_q.front();
                m_q.pop();
                cout << "线程" << this_thread::get_id() << ", 拿到:" << message <<endl;
            }
            

            this_thread::sleep_for(chrono::milliseconds(1));
        }
    }
};

int main()
{
    AA aa;

    thread t1(&AA::outcache,&aa);
    thread t2(&AA::outcache,&aa);
    thread t3(&AA::outcache,&aa);

    this_thread::sleep_for(chrono::seconds(2));
    aa.incache(2);

    this_thread::sleep_for(chrono::seconds(2));
    //aa.incache(5);

    t1.join();
    t2.join();
    t3.join();
}
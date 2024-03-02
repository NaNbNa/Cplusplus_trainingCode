#include <iostream>
#include <thread>
#include <functional>
using namespace std;           //可变参数

void show0()
{
    cout << "亲爱的, 你是一只傻傻鸟" <<endl;
}

void show1(const string& message)
{
    cout << "亲爱的, " << message <<endl;
}

struct CC
{
  void show2(int bh,const string& message)
  {
    cout << "亲爱的" << bh << "号, " << message <<endl;
  }  
};

template <typename Fn,typename ...Args>
auto show(Fn&& fn,Args&& ...args) -> decltype(bind(forward<Fn>(fn),forward<Args>(args)...))
{
    cout << "表白前的工作" << endl;

    auto f = bind(forward<Fn>(fn),forward<Args>(args)...);
    f();
    cout << "表白成功" <<endl;

    return f;
}
int main()
{
    show(show0);
    show(show1,"你是一只傻傻鸟");
    CC cc;
    show(&CC::show2,&cc,3,"你是一只傻傻鸟");

    // thread t1(show0);
    // thread t2(show1,"你是一只傻傻鸟");
    // CC cc;
    // thread t3(&CC::show2,&cc,3,"你是一只傻傻鸟");

    // t1.join();
    // t2.join();
    // t3.join();
}
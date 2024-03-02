#include <iostream>
#include <functional>

using namespace std;        //包装器和绑定器取代虚函数

struct hero
{
    // virtual void show()
    // {
    //     cout << "英雄释放了技能" <<endl;
    // }
    function<void()> m_callback;

    template <typename Fn,typename ...Args>
    void callback(Fn&& fn,Args&& ...args)
    {
        m_callback = bind(forward<Fn>(fn),forward<Args>(args)...);
    }

    void show()
    {
        m_callback();
    }
};

struct xs:public hero
{
    void show() 
    {
        cout << "西施释放了技能" <<endl;
    }
};

struct hx:public hero
{
    void show()
    {
        cout << "韩信释放了技能" <<endl;
    }
};

int main()
{
    int id = 0;
    cout << "请输入英雄(1-西施,2-韩信):" ;
    cin >> id;

    hero* ptr = nullptr;

    if(id==1)
    {
        ptr = new xs;
        ptr->callback(&xs::show,static_cast<xs*>(ptr));
    }
    else if( id==2)
    {
        ptr = new hx;
        ptr->callback(&hx::show,static_cast<hx*>(ptr));
    }
    
    if(ptr!=nullptr)
    {
        ptr->show();
        delete ptr;
    }
}

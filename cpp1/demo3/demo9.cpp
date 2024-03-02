#include <iostream> 
#include <memory>

using namespace std;        //weak_ptr的用法

class BB;

class AA
{
public:
    string m_name;
    AA()
    {
        cout  << "调用了构造函数AA():" << m_name <<endl;
    }
    AA(const string& name):m_name(name)
    {
        cout << "调用了构造函数AA(const string& name):" << m_name <<endl;
    }

    ~AA()
    {
        cout << "调用了析构函数~AA():" << m_name <<endl;
    }
    weak_ptr<BB> m_p;
    //shared_ptr<BB> m_p;
};

class BB
{
public:
    string m_name;
    BB()
    {
         cout  << "调用了构造函数BB():" << m_name <<endl;
    }
    BB(const string& name):m_name(name)
    {
        cout << "调用了构造函数BB(const string& name):" << m_name <<endl;
    }
    ~BB()
    {
        cout << "调用了析构函数~BB():" << m_name <<endl;
    }
    weak_ptr<AA> m_p;
    //shared_ptr<AA> m_p;
};

int main()
{
    // shared_ptr<AA> pa = make_shared<AA> ("西施a");
    // shared_ptr<BB> pb = make_shared<BB> ("西施b");

    // cout << "pa.use_count()= " << pa.use_count() <<endl;
    // cout << "pb.use_count()= " << pb.use_count() <<endl;

    // pa->m_p = pb;
    // pb->m_p = pa;

    // cout << "pa.use_count()= " << pa.use_count() <<endl;
    // cout << "pb.use_count()= " << pb.use_count() <<endl;

    shared_ptr<AA> pa = make_shared<AA> ("西施a");
    shared_ptr<BB> pb = make_shared<BB> ("西施b");

    pa->m_p = pb;
    pb->m_p = pa;

    shared_ptr<BB> pp = pa->m_p.lock();         //线程安全
    if(pp=nullptr)
        cout << "语句块内部:pa->m_p已过期" <<endl;
    else 
        cout << "语句块内部:pa->m_p.lock()->m_name=" << pa->m_p.lock()->m_name <<endl;

    shared_ptr<AA> pp1 = pb->m_p.lock();        //线程安全
    if(pp1==nullptr)
        cout << "语句块内部:pb->m_p已过期" <<endl;
    else 
        cout << "语句块内部:pb->m_p.lock()->m_name=" << pb->m_p.lock()->m_name <<endl;
}
#include <iostream> 
#include <memory>

using namespace std;        //share_ptr指针的技巧
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
};

int main()
{
    // AA* p = new AA("西施");
    // shared_ptr<AA> p0(p);
    // shared_ptr<AA> p1(p0);
    // shared_ptr<AA> p2(p1);

    // cout << "m_name= " << p0->m_name <<endl;
    // cout << "p0.use_count= " << p0.use_count() <<endl;
    // cout << "m_name= " << p1->m_name <<endl;
    // cout << "p1.use_count= " << p1.use_count() <<endl;

    // cout << "p0.get()=" << p0.get() << endl;
    // cout << "p1.get()=" << p1.get() << endl;
    // cout << "p2.get()=" << p2.get() << endl;

    shared_ptr<AA> pa0(new AA("西施a"));
    shared_ptr<AA> pa1 = pa0;
    shared_ptr<AA> pa2 = pa1;
    cout << "pa0.use_count()= " << pa0.use_count() <<endl;  //3

    shared_ptr<AA> pb0(new AA("西施b"));
    shared_ptr<AA> pb1 = pb0;
    cout << "pb0.use_count()= "<< pb0.use_count() <<endl;   //2

    pb1 = pa1;
    pb0 = pa1;

    cout << "pa0.use_count()= " << pa0.use_count() <<endl;
    cout << "pb0.use_count()= "<< pb0.use_count() <<endl;

    pa1.reset();
    cout << "pa0.use_count()= " << pa0.use_count() <<endl;
}
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

void deletefunc(AA* a)
{
    cout << "自定义删除器" << endl;
    delete a;
}

struct deleteclass
{
    void operator()(AA* a)
    {
        cout << "自定义删除器(仿函数)" <<endl;
        delete a;
    }
};

auto deleterlamb = [](AA* a)
{
    cout << "自定义删除器(Lambda)" <<endl;
    delete a;
};

int main()
{
    //shared_ptr<AA> pa1(new AA("西施"));

    // AA a("西施");        
    // shared_ptr<AA> pa1(&a, deletefunc); //false,栈上分配的内存-类,main结束时自动调用析构函数
    //shared_ptr<AA> pa1(new AA("西施"), deletefunc);
    //shared_ptr<AA> pa1(new AA("西施"), deleteclass());
    //shared_ptr<AA> pa1(new AA("西施"), deleterlamb());

    //unique_ptr<AA,decltype(deletefunc)*> pu1 (new AA("西施"),deletefunc);
    //unique_ptr<AA,void(*)(AA*)> pu1 (new AA("西施"),deletefunc);        //函数指针
    //unique_ptr<AA,deleteclass> pu1(new AA("西施"),deleteclass());
    unique_ptr<AA, decltype(deleterlamb)> pu1(new AA("西施"),deleterlamb);
}
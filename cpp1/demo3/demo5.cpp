#include <iostream>
#include <memory>

using namespace std;    //智能指针的基础

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


// void func(unique_ptr<AA> p)     //false,因为是传值,拷贝构造函数不可使用
// {
//     cout << "调用了func(unique_ptr<AA> p)" <<endl;
// }

void func(unique_ptr<AA>& p)    
{
    cout << "调用了func(unique_ptr<AA> p)" <<endl;
}
int main()
{
    AA* p = new AA("西施");
    
    unique_ptr<AA> p1(p);
    //unique_ptr<AA> p1(new AA("西施"));
    // unique_ptr<AA> p2 = p;  //false,因为explicit
    // unique_ptr<AA> p3 = new AA("西施"); //false,因为explicit
    //unique_ptr<AA> p4 = p1; //false, 拷贝构造函数被禁止使用
    // unique_ptr<AA> p5;
    // p5 = p1;    //false,赋值函数已被禁用

    // unique_ptr<AA> p1(p);       //段错误,因为多次释放内存,该构造函数存在缺点
    // unique_ptr<AA> p2(p);
    // unique_ptr<AA> p3(p);

    cout << "裸指针的值是:\t" << p <<endl;
    //cout << "p1输出的结果是:\t" << (p1) <<endl;
    cout << "p1.get()输出的结果是:\t" << p1.get() <<endl;
    cout << "p1的地址是:\t" << &p1 <<endl;

    // cout << "(*p1).m_name=\t" << (*p1).m_name <<endl;  //重载*和->操作符
    // cout << "p1->m_name=\t" << p1->m_name <<endl;
    // cout << "(*p).m_name=\t" << (*p).m_name <<endl;  //重载*和->操作符
    // cout << "p->m_name=\t" << p->m_name <<endl;
    //delete p;

    func(p1);  

    //p1++;   //不支持++,--,+,-
}
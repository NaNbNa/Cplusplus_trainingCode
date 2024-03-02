#include <iostream>
#include <string.h>

using namespace std;
class callComers
{
public:
    string m_name;
    string m_tel;
protected:
    int m_a;
private:
    int m_b;

public:
    callComers()        //必须是public
    {
        m_name = "某女", m_tel = "不祥";
    }

    void sing()
    {
        cout << "你是一只小小鸟!" <<endl;
    }
    void setname(const string& name)
    {
        m_name = name;
    }
    void settel(const string tel)
    {
        m_tel = tel;
    }

    void func()
    {
        m_b =11; cout << "m_b=" << m_b <<endl;
    }
};

class cgirl:public callComers
{
// private:
//     using callComers::m_a;      //protected改成private

public:
    int m_bh;
    using callComers::m_a;
    cgirl()
    {
        m_bh =8;
    }
    void show()
    {
        setname("西施");    //可以访问
        //m_b =0;         //不可访问
        func();             //间接访问private
        cout << "编号:" << m_bh << ", 姓名:" << m_name << ", 联系电话:" << m_tel<<endl;
    }
    
};
int main()
{
    cgirl g;
    //g.setname("西施");      //setname成为了私有成员,不可访问
    g.show();

    cgirl b;
    b.m_a;      //using 改变权限,但不可更改基类中是private的
    
}
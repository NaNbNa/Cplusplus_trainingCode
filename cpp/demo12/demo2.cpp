#include <iostream>
#include <string.h>

using namespace std;
class hero
{
public:
    int viability;
    int attack;
    virtual void skill1()
    {
        cout << "英雄释放了一技能." << endl;
    }
    virtual void skill2()
    {
        cout << "英雄释放了二技能." << endl;
    }
    virtual void uskill()
    {
        cout << "英雄释放了大绝招." << endl;
    }
};

class xs:public hero
{
public:
    void skill1()
    {
        cout << "西施释放了一技能." << endl;
    }
    void skill2()
    {
        cout << "西施释放了二技能." << endl;
    }
    void uskill()
    {
        cout << "西施释放了大招." << endl;
    }
};

class lb:public hero
{
public:
    void skill1()
    {
        cout << "李白释放了一技能." << endl;
    }
    void skill2()
    {
        cout << "李白释放了二技能." << endl;
    }
    void uskill()
    {
        cout << "李白释放了大招." << endl;
    }
};

class hx:public hero
{
public:
    void skill1()
    {
        cout << "韩信释放了一技能." << endl;
    }
    void skill2()
    {
        cout << "韩信释放了二技能." << endl;
    }
    void uskill()
    {
        cout << "韩信释放了大招." << endl;
    }
};
int main()
{
    int id =0;
    cout << "请输入英雄(1-西施;2-韩信;3-李白):" ;
    cin >> id;

    hero *ptr = nullptr;

    if(id==1)   //不适用多态,只使用派生类的成员函数
    {
        ptr= new xs;
    }
    else if(id==2)
    {
        ptr = new hx;
    }
    else if(id==3)
    {
        ptr = new lb;
    }

    if(ptr!=0)
    {
        ptr->skill1();
        ptr->skill2();
        ptr->uskill();
        delete ptr;
    }

    // if(id==1)   //不适用多态,只使用派生类的成员函数
    // {
    //     xs h;           //if中可以放定义,但是不能在if外面使用
    //     h.skill1();     //这些相同代码不可放到if外,因为未定义
    //     h.skill2();
    //     h.uskill();
    // }
    // else if(id==2)
    // {
    //     hx h;           //if中可以放定义,但是不能在if外面使用
    //     h.skill1();     //这些相同代码不可放到if外,因为未定义
    //     h.skill2();
    //     h.uskill();
    // }
    // else if(id==3)
    // {
    //     lb h;
    //     h.skill1();
    //     h.skill2();
    //     h.uskill();
    // }
}
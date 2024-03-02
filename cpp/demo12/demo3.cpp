#include <iostream>
#include <string.h>

using namespace std;            //多态的对象模型--原理的意思
class hero
{
public:
    int viability;
    int attack;
    void skill1()
    {
        cout << "英雄释放了一技能." << endl;
    }
    void skill2()
    {
        cout << "英雄释放了二技能." << endl;
    }
    void uskill()
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

}
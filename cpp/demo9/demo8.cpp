#include <iostream>
#include <string.h>

using namespace std;

class cgirl;
class cboy
{
public:
    void bfunc1(const cgirl& g);
    void bfunc2(const cgirl& g);
};

class cgirl
{
//friend int main();
//friend void func();
//friend class cboy;
friend void cboy::bfunc1(const cgirl& g);
public:
    string m_name;

    cgirl()
    {
        m_name="西施";m_xw = 87;
    }

    void showname()
    {
        cout << "name:\t" << m_name <<endl;
    }
private: 
    int m_xw;
    void showxw() const
    {
        cout << "xw is\t" << m_xw <<endl;
    }
};

void cboy::bfunc1(const cgirl& g)
{
    cout << "my girlfriend1' name is:\t" << g.m_name <<endl;
    cout << "my girlfiend1's xw is:\t" << g.m_xw <<endl;
    g.showxw();
}
void cboy::bfunc2(const cgirl& g)
{
    cout << "my girlfriend2' name is:\t" << g.m_name <<endl;
}


// void func()
// {
//     cgirl g;
//     g.showname();
//     g.showxw();
// }
int main()
{
    //func();
    cgirl g;
    cboy b;
    b.bfunc2(g);
    b.bfunc1(g);
}
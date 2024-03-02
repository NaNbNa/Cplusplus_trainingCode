#include <iostream>

using namespace std;

class cgirl
{
    string m_name;
    int m_yz;
    int m_sc;
    int m_acting;

public:
    cgirl(string name, int yz,int sc,int acting)
    {
        m_name = name;m_yz = yz;m_sc = sc;m_acting = acting;
    }
    bool operator==(const cgirl& g)
    {
        if((m_yz+m_sc+m_acting) == (g.m_yz+g.m_sc+g.m_acting))
            return true;
        return false;
    }
    bool operator>(const cgirl& g)
    {
        if((m_yz+m_sc+m_acting) < (g.m_yz+g.m_sc+g.m_acting))
            return true;
        return false;
    }
    bool operator<(const cgirl& g)
    {
        if((m_yz+m_sc+m_acting) > (g.m_yz+g.m_sc+g.m_acting))
            return true;
        return false;
    }
};

int main()
{
    cgirl g1("西施",1,2,3), g2("冰冰", 3,1,1);
    if(g1==g2)
        cout << "same!" <<endl;
    else if(g1>g2)
        cout << "g1 bigger!" <<endl;
    else if(g1<g2)
        cout << "g2 bigger!" <<endl;
}
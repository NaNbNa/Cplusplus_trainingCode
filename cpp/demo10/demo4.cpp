#include <iostream>
using namespace std;

class cgirl
{
private:
    string m_boys[3];
public:
    string m_name;

    cgirl()
    {
        m_boys[0] = "子都", m_boys[1]= "潘安", m_boys[2] = "宋玉";
        m_name.clear();
    }
    void show()
    {
        cout << m_boys[0] << ", " << m_boys[1] << ", " << m_boys[2] <<endl;
    }

    string& operator[](int i)
    {
        return m_boys[i];
    }
    const string& operator[](int i) const
    {
        return m_boys[i];
    }
};

int main()
{
    cgirl g;
    // g.boys(1) = "hello";
    // cout << "boys[1]:" << g.boys(1) << endl;
    g[1] = "hello";
    cout << "g[1]:" << g[1] << endl;
    g.show();
    const cgirl g1 =g;
    cout << "g1[1]:" << g1[1] <<endl;

}
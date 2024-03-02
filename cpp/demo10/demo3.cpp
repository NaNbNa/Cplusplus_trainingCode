#include <iostream>
using namespace std;

class cgirl
{
friend ostream& operator<<(ostream&cout, const cgirl& g);
    string m_name;
    int m_xw;
    int m_score;
public:
    cgirl()
    {
        m_name = "西施"; m_xw = 87;m_score = 30;
    }
    void show()
    {
        cout << "姓名:" << m_name << "; 胸围:" << m_xw << "; 评分:" << m_score <<endl;
    }
    // ostream& operator<<(ostream&cout)  //第一个参数是自身对象
    // {
    //     cout << "姓名:" << m_name << "; 胸围:" << m_xw << "; 评分:" << m_score;
    //     return cout;
    // }
};

ostream& operator<<(ostream&cout, const cgirl& g)
{
    cout << "姓名:" << g.m_name << "; 胸围:" << g.m_xw << "; 评分:" << g.m_score ;
    return cout;
}

int main()
{
    cgirl g;
    //g << cout <<endl;用于成员函数时,cout位置
    cout << g <<endl;
}
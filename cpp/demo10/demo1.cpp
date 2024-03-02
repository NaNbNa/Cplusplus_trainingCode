#include <iostream>
#include <string.h>

using namespace std;
class cgirl
{
friend cgirl& operator+(cgirl& g, int score);
friend cgirl& operator+(int score,cgirl& g);
friend cgirl& operator+(cgirl& g,cgirl& g1);
friend cgirl& operator-(cgirl& g, int score);
private:
    int m_xw;
    int m_score;
public:
    string m_name;

    cgirl()
    {
        m_name="西施";m_xw = 87;m_score =30;
    }

    void show()
    {
        cout << "the name is:\t" << m_name <<endl;
        cout << "the xw is:\t" << m_xw <<endl;
        cout << "the score is:\t" << m_score <<endl;
    }
    // cgirl& operator+(int score)
    // {
    //     m_score = m_score + score;
    //     return *this;
    // }

    // void operator-(int& g,int score)     //false demo
    // {
    //     g  = g - score;
    // }
    
};

cgirl& operator+(cgirl& g,int score)
{
    g.m_score = g.m_score + score;
    return g;
}
cgirl& operator+(int score,cgirl& g)
{
    g.m_score = g.m_score + score;
    return g;
}
cgirl& operator+(cgirl& g,cgirl& g1)
{
    g.m_score = g.m_score + g1.m_score;
    return g;
}

// cgirl& operator-(cgirl& g,int score)
// {
//     g.m_score = g.m_score - score;
//     return g;
// }




int main()
{
    cgirl g;

    //addscore(g,30);
    //operator+(g,30);
    g + 30;
    g.show();
    g = 20 +5 +2 +g;
    g = g + 20 +5 +2 +g;
    //g = g + g;
    //g = operator-(operator-(operator-(g,20),5),2);
    g.show();
}
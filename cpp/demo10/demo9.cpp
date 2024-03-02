#include <iostream>
#include <string.h>

using namespace std;    //重载一元运算符,例子是++和--
class cgirl
{
public:
    string m_name;
    int m_ranking;

    cgirl()
    {
        m_name = "西施"; m_ranking=5;
    }
    void show() const
    {
        cout << "姓名:" << m_name<< ", 排名:" << m_ranking <<endl;
    }

    cgirl& operator++()     //++前置
    {
        m_ranking ++;
        return *this;
    }

    // cgirl& operator++(int)     //++后置,不符合后置++的语义
    // {
    //     m_ranking ++;
    //     return *this;
    // }

    cgirl operator++(int)     //++后置,符合后置++的语义
    {
        cgirl temp = *this;
        m_ranking ++;
        return temp;        //临时对象
    }
};
int main()
{
    // cgirl g;
    // ++g;   
    // ++(++(++g));           //++(++(++i))

    // g.show();

    // cgirl g1;
    
    // (((g1++)++)++);      //看似可以,与下面对比,其实不能嵌套
    // g1.show();
    
    int i=5, j=5;
    int x = (++(++(++i)));  cout << "x=" << x << ", i=" << i <<endl;
    //int y = (((j++)++)++);  cout << "y=" << y << ", j=" << j <<endl;  //后置的自增不可嵌套,会出现错误
    int y = j++ ; cout << "y=" << y << ", j=" << j <<endl;

    cgirl g1,g2;
    cgirl g3 = ++(++(g1));
    cout << "girl3.m_ranking=" << g3.m_ranking << ", girl1.m_ranking=" << g1.m_ranking <<endl;
    cgirl g4 = g2++;    
    cout << "girl4.m_ranking=" << g4.m_ranking << ", girl2.m_ranking=" << g2.m_ranking <<endl;
}
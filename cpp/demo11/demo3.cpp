#include <iostream>
#include <string.h>

using namespace std;

class callComers
{
public:
    string m_name;
    string m_tel;

    callComers()
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
};

class cgirl:public callComers
{
public:
    int m_bh;

    cgirl()
    {
        m_bh =8;
    }
    void show()
    {
        cout << "编号:" << m_bh << ", 姓名:" << m_name << ", 联系电话:" << m_tel<<endl;
    }
};
class sort
{
    int m_data[30];
    void print();
};
// class bubblesort
// {
//     int m_data[30];
//     void sort();
//     void print();
// };
// class seletesort
// {
//     int m_data[30];
//     void sort();
//     void print();
// };
// class shellsort
// {
//     int m_data[30];
//     void sort();
//     void print();
// };


class bubblesort:public sort
{
    void sort();
};
class seletesort:public sort
{
    //int m_data[30];
    void sort();
    //void print();
};
class shellsort:public sort
{
    //int m_data[30];
    void sort();
    //void print();
};

int main()
{
    cgirl g;
    g.setname("西施");
    g.show();
}


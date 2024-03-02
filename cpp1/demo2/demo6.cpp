#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <list>

using namespace std;        //queue--无迭代器

class cgirl
{
public:
    int m_bh;
    string m_name;

    cgirl(const int& bh,const string& name):m_bh(bh),m_name(name)
    {
        cout << "调用了cgirl(const int& bh,const string& name)" <<endl;
    }
};
int main()
{
    //queue<cgirl,list<cgirl>> q;
    //queue<cgirl,deque<cgirl>> q;
    queue<cgirl> q;     // 缺省,deque
    //queue<cgirl,vector<cgirl>> q; //false,不可用vector

    q.push(cgirl(3,"西施"));     //效率低
    q.emplace(8,"冰冰");        //效率高
    q.push(cgirl(5,"咪咪"));
    q.push(cgirl(2,"西瓜"));

    while(q.empty()==false)
    {
        cout << "编号: " << q.front().m_bh << ", 姓名: " << q.front().m_name <<endl;
        q.pop(); 
    }
}
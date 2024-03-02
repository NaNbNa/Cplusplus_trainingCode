#include <iostream>
#include <string.h>
#include <list>
#include <vector>
using namespace std;        //list的构造函数

int main()
{
    //构造1
    list<int> l1;       
    cout << "li.size()=" << l1.size() <<endl;   //无capacity

    //构造2
    // list<int> l2{1,2,3,4,5,6,7,8,9,10}; 
    // list<int> l2({1,2,3,4,5,6,7,8,9,10});
    list<int> l2={1,2,3,4,5,6,7,8,9,10}; //转换函数
    for(auto val:l2)
    {
        cout << val <<"  ";
    }
    cout <<endl;

    //构造3:拷贝构造函数
    list<int> l3 = l2;
    for(auto val:l3)
    {
        cout << val << "  ";
    }
    cout <<endl;

    //构造4:迭代器不支持+,-
    //list<int> l4(l3.begin(),l3.end()-3);
    list<int> l4(l3.begin(),l3.end());
    for(auto val:l4)
    {
        cout << val << "  ";
    }
    cout <<endl;

    vector<int> v1 ={1,2,3,4,5,6,7,8,9,10};
    list<int> l5(v1.begin()+2,v1.end()-3);
    for(auto val:l5)
    {
        cout << val << "  ";
    }
    cout <<endl;

    int a1[] = {1,2,3,4,5,6,7,8,9,10};
    list<int> l6(a1+3,a1+10-2);
    for(auto val:l6)
    {
        cout << val << "  ";
    }
    cout <<endl;

    char str[] = "hello,world";
    string s1(str+1,str+7);
    for(auto val:s1)
    {
        cout << val << "  ";
    }
    cout <<endl;

    vector<int> v2(l3.begin(),l3.end());
    for(auto val:v2)
    {
        cout << val << "  ";
    }
    cout <<endl;
}
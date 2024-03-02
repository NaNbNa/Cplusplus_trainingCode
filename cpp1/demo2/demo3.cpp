#include <iostream>

using namespace std;

template <class  T1,class T2>
struct Pair
{
    T1 first;
    T2 second;
public:
    Pair()
    {
        cout << "调用了默认构造函数" <<endl;
    }
    Pair(const T1& val1,const T2& val2):first(val1),second(val2)
    {
        cout << "调用了有两个参数的构造函数" <<endl;
    }
    Pair(const Pair<T1,T2>& p):first(p.first),second(p.second)
    {
        cout << "调用了拷贝构造函数" <<endl;
    }

};

template <class T1, class T2>
Pair<T1,T2> make_Pair(const T1& first,const T2& second)
{
    return Pair<T1,T2>(first,second); //返回临时对象
    // Pair<T1,T2> p(first,second);
    // return p;               //返回局部对象,vs调用拷贝构造函数,Linux不会
}

int main()
{
    // pair<int,string> p0;
    // cout << "p0 first=" << p0.first << ", second=" << p0.second <<endl;

    // pair<int,string> p1(1,"西施");
    // cout << "p1 first=" << p1.first << ", second=" << p1.second <<endl;

    // pair<int,string> p2 =p1;    //拷贝构造
    // cout << "p2 first=" << p2.first << ", second=" << p2.second <<endl;

    // pair<int,string> p3={3,"西施3"};
    // //pair<int,string> p3{3,"西施3"};
    // cout << "p3 first=" << p3.first << ", second=" << p3.second <<endl;

    // auto p4 = pair<int,string>(4,"西施4");  //匿名对象
    // cout << "p4 first=" << p4.first << ", second=" << p4.second <<endl;

    // auto p5 = make_pair<int,string>(5,"西施5");     //make_pair+临时对象
    // cout << "p5 first=" << p5.first << ", second=" << p5.second <<endl;

    auto p4 = Pair<int,string>(4,"西施4");  //匿名对象
    cout << "p4 first=" << p4.first << ", second=" << p4.second <<endl;

    auto p5 = make_Pair<int,string>(5,"西施5");     //make_pair(因为是函数,创建临时对象)
    cout << "p5 first=" << p5.first << ", second=" << p5.second <<endl;

    // pair<int,string> p6 = make_pair(6,"西施6");     //慎用,make_pair自动推导,临时对象
    // cout << "p6 first=" << p6.first << ", second=" << p6.second <<endl;

    // auto p7 = make_pair(7,"西施7");                //慎用    
    // cout << "p7 first=" << p7.first << ", second=" << p7.second <<endl;

    // p5.swap(p4);
    // cout << "p4 first=" << p4.first << ", second=" << p4.second <<endl;
    // cout << "p5 first=" << p5.first << ", second=" << p5.second <<endl;

    // struct st_girl
    // {
    //     string name;
    //     int age;
    //     double height;
    // };
    // pair<int,st_girl> p = {3,{"西施",23,48.6}};
    // cout << "p.first=" << p.first <<endl;
    // cout << "p.second,name=" << p.second.name <<endl;
    // cout << "p.second.age=" << p.second.age <<endl;
    // cout << "p.second.height=" << p.second.height <<endl;
}
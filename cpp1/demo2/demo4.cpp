#include <iostream>
#include <map>

using namespace std;    //map

class cgirl
{
public:
    string m_name;
    int m_age;

    cgirl(const string& name,const int age):m_name(name),m_age(age)
    {
        cout << "调用了两个参数的构造函数" <<endl;
    }
    cgirl(const cgirl& g):m_name(g.m_name),m_age(g.m_age)
    {
        cout << "调用了拷贝构造函数" <<endl;
    }
};
int main()
{
    //构造1
    // map<int,string> m1;

    // //2
    // map<int,string> m2{{8,"冰冰"},{3,"西施"},{1,"咪咪"},{7,"金莲"},{5,"西瓜"}};

    // for(auto& val:m2)
    // {
    //     cout << val.first << "," << val.second << "  ";
    // }
    // cout << endl;

    // //3
    // map<int,string> m3 = m2;
    //  for(auto& val:m3)
    // {
    //     cout << val.first << "," << val.second << "  ";
    // }
    // cout << endl;

    // //4
    // auto first = m3.begin();first++;
    // auto last = m3.end(); last++;
    // map<int,string> m4(first,last);
    // for(auto& val:m4)
    // {
    //     cout << val.first << "," << val.second << "  ";
    // }
    // cout << endl;

    // map<string,string> m{{"08","冰冰"},{"03","西施"}, {"01","咪咪"},{"07","金莲"},{"05","西瓜"}};
    // //map<string,string> m({{"08","冰冰"},{"03","西施"}, {"01","咪咪"},{"7","金莲"},{"5","西瓜"}});

    // cout << "m[08]=" << m["08"] <<endl;
    // cout << "m[09]=" << m["09"] <<endl;     //insert 09

    // m["07"] = "花花";
    // m["12"] = "小乔";       //insert 12
    // for(auto& val:m)
    // {
    //     cout << val.first << "," << val.second <<"  ";
    // }
    // cout <<endl;

    // map<int,string> m;

    // m.insert({{8,"冰冰"},{3,"西施"}});
    // m.insert({pair<int,string>(1,"咪咪"), make_pair<int,string>(7,"金莲"),{5,"西瓜"}});
    // m.insert({{18,"冰冰"},{3,"西施"}});

    // auto ret = m.insert(pair<int,string>(12,"花花"));

    // if(ret.second == true)
    // {
    //     cout << "插入成功:" << ret.first->first << "," << ret.first->second <<endl;
    // }
    // else
    // {
    //     cout << "插入失败" <<endl;
    // }
    // for(auto& val:m)
    // {
    //     cout << val.first << "," << val.second <<" ";
    // }
    // cout <<endl;

    // map<int,string> m;           //emplace
    // //auto ret = m.emplace(pair<int,string>(12,"花花"));
    // auto ret = m.emplace(12,"花花");
    // if(ret.second == true)
    // {
    //     cout << "插入成功:" << ret.first->first << "," << ret.first->second <<endl;
    // }
    // else
    // {
    //     cout << "插入失败" <<endl;
    // }

    // for(auto& val:m)
    // {
    //     cout << val.first << "," << val.second <<" ";
    // }
    // cout <<endl;

    // map<int,cgirl> mm;
    // //mm.insert(pair<int,cgirl>(8,cgirl("冰冰",18)));   //两次构造函数
    // //mm.emplace(8,cgirl("冰冰",18));     //一次构造函数
    // //mm.emplace(8,"冰冰",18);       //false
    // mm.emplace(piecewise_construct,forward_as_tuple(8),forward_as_tuple("冰冰",18)); //不调用构造函数--分段构造技术
    // for(auto& val:mm)
    // {
    //     cout << val.first << "," << val.second.m_name << "," << val.second.m_age <<" ";
    // }
    // cout <<endl;

    map<string,string> mm{{"08","冰冰"},{"03","西施"}, {"01","咪咪"},{"07","金莲"},{"05","西瓜"}};  //带提示的emplace_hint
    mm.emplace_hint(mm.begin(),piecewise_construct,forward_as_tuple("23"),forward_as_tuple("冰冰")); //不调用构造函数--分段构造技术
    for(auto& val:mm)
    {
        cout << val.first << "," << val.second  <<" ";
    }
    cout <<endl;
}
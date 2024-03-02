#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;    //umap--结构哈希表

template <class K, class V>
using umap = std::unordered_map<K,V>;

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
    // //构造1
    // umap<int,string> m1;

    // //2
    // umap<int,string> m2{{8,"冰冰"},{3,"西施"},{1,"咪咪"},{7,"金莲"},{5,"西瓜"}};

    // for(auto& val:m2)
    // {
    //     cout << val.first << "," << val.second << "  ";
    // }
    // cout << endl;

    // //3
    // umap<int,string> m3 = m2;
    // for(auto& val:m3)
    // {
    //     cout << val.first << "," << val.second << "  ";
    // }
    // cout << endl;

    // //4
    // auto first = m3.begin();first++;
    // auto last = m3.end(); //last--;
    // umap<int,string> m4(first,last);
    // for(auto& val:m4)
    // {
    //     cout << val.first << "," << val.second << "  ";
    // }
    // cout << endl;

    // umap<int,string> m;
    // cout << m.bucket_count() <<endl;       //缺省桶数
    
    // size_t item = m.bucket_count();

    // for(int ii=0;ii<200000;ii++)            //插入20w元素
    // {
    //     char name[50];sprintf(name,"西施%d", ii);  
    //     m.emplace(ii,name);

    //     if(item!=m.bucket_count())
    //     {
    //         cout << m.bucket_count() << endl;
    //         item = m.bucket_count();
    //     }
    // }
    
    // umap<int,string> m;
    // m.max_load_factor(2);
    // cout << "最大装填因子: " << m.max_load_factor() <<endl;
    // cout << "当前桶数: " << m.bucket_count() <<endl;
    // cout << "当前装填因子: " << m.load_factor() <<endl;

    // cout << "------------------" << endl;
    // m.insert({{1,"西施1"}, {2,"西施2"},{3,"西施3"},{4,"西施4"}});   //4
    // cout << "当前桶数: " << m.bucket_count() <<endl;
    // cout << "当前装填因子: " << m.load_factor() <<endl;

    // cout << "------------------" << endl;
    // m.insert({{5,"西施5"}, {6,"西施6"},{7,"西施7"}});                //3
    // cout << "当前桶数: " << m.bucket_count() <<endl;
    // cout << "当前装填因子: " << m.load_factor() <<endl;

    // cout << "------------------" << endl;                       //3
    // m.insert({{15,"西施5"}, {16,"西施6"},{17,"西施7"}});
    // cout << "当前桶数: " << m.bucket_count() <<endl;
    // cout << "当前装填因子: " << m.load_factor() <<endl;

    // cout << "------------------" << endl;
    // m.emplace(9,"西瓜");                                            //1
    // cout << "当前桶数: " << m.bucket_count() <<endl;
    // cout << "当前装填因子: " << m.load_factor() <<endl;

    // umap<int,string> m;                          //迭代器
    // m.max_load_factor(5);
    // m.insert({{1,"西施1"}, {2,"西施2"},{3,"西施3"},{4,"西施4"}});
    // m.insert({{5,"西施5"}, {6,"西施6"},{7,"西施7"},{8,"西施8"}});  
    // m.insert({{11,"西施11"}, {12,"西施12"},{13,"西施13"},{14,"西施14"}});
    // m.insert({{15,"西施15"}, {16,"西施16"},{17,"西施17"},{18,"西施18"}});     //16
    // m.emplace(9,"西瓜");    

    // int jj=0;
    
    // for(auto& val:m)
    // {
    //     cout << val.first << ", " << val.second <<"\t";
    //     if(jj%5==0)
    //         cout <<endl;
    //     jj++;
    // }  
    // cout <<endl;
    // cout << "------------------" << endl;  


    // for(int ii=0;ii<m.bucket_count();ii++)
    // {
    //     cout << "桶" << ii << ": ";
    //     for(auto it = m.begin(ii);it!=m.end(ii);it++)       //umap每个桶的迭代器使用
    //     {
    //         cout << it->first <<", " << it->second << "\t";
    //     }
    //     cout << endl;
    // }

    // umap<int,string> m;                          //umap扩容的本质
    // //m.max_load_factor(5);
    // m.insert({{1,"西施1"}, {2,"西施2"},{3,"西施3"},{4,"西施4"}});
    // m.insert({{5,"西施5"}, {6,"西施6"}});  

    // for(int ii=0;ii<m.bucket_count();ii++)
    // {
    //     cout << "桶" << ii << ", 大小是: " << m.bucket_size(ii) << ", 内容:\t";
    //     for(auto it = m.begin(ii);it!=m.end(ii);it++)       //umap每个桶的迭代器使用
    //     {
    //         cout << it->first <<", " << it->second << "\t";
            
    //     }
    //     cout << endl;
    // }

    // cout << "------------------" << endl;  
    // m.insert({{21,"西施1"}, {22,"西施2"},{23,"西施3"},{24,"西施4"}});
    // m.insert({{25,"西施5"}, {26,"西施6"},{20,"西施0"}});

    // for(int ii=0;ii<m.bucket_count();ii++)
    // {
    //     cout << "桶" << ii << ", 大小是: " << m.bucket_size(ii) << ", 内容:\t";
    //     for(auto it = m.begin(ii);it!=m.end(ii);it++)       //umap每个桶的迭代器使用
    //     {
    //         cout << it->first <<", " << it->second << "\t";
            
    //     }
    //     cout << endl;
    // }

    cout << "开始创建umap: " << time(0) <<endl;         //重新哈希的时间消耗
    umap<int,string> m(10000000);   //10,000,000
    for(int ii =0;ii<10000000;ii++)
    {
        //m.insert({ii,"西施."});
        m.emplace(ii,"西施.");
    }
    cout << "创建umap完成:" << time(0) <<endl;
    
}
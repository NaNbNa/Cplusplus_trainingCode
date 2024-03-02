#include <iostream>
#include <string.h>
#include <vector>
#include <list>

using namespace std;            //迭代器操作,失效
                                //使用迭代器遍历时,如果需要插入或者删除,需要考虑迭代器会失效

struct Node
{
    int item;
    Node* next;
};

int* find_(int* arr,int n, const int& val)
{
    cout << "具体1" <<endl;
    for(int ii=0;ii<n;ii++)
        if(arr[ii]==val)
            return &arr[ii];
    return nullptr;
}
int* find_(int* begin,int* end, const int& val)
{
    cout << "具体2" <<endl;
    for(int *iter = begin;iter!=end;iter++)
    {
        if(*iter==val) return iter;
    }
    return nullptr;
}
Node* find_(Node* head,Node* end,const Node& val)   //end固定为nullptr
{
    for(Node* iter =head;iter!=end;iter = iter->next)
    {
        if(iter->item==val.item) return iter;
    }
    return nullptr;
}

template <typename T1,typename T2>
T1 find_(T1 begin, T1 end,const T2&val)
{
    cout << "模板" <<endl;
    for(T1 iter=begin;iter!=end;iter++)
    {
        if(*iter==val) return iter;
    }
    return end;
}

int main()
{
    // vector<int> vv = {1,2,3,4,5};
    // vector<int>::iterator it2 = find_(vv.begin(),vv.end(),3);
    // if(it2!=vv.end()) cout << "查找成功" <<endl;
    // else cout << "查找失败" <<endl;

    // list<int> ll = {1,2,3,4,5};
    // list<int>::iterator it3 = find_(ll.begin(),ll.end(),3);
    // if(it3!=ll.end()) cout << "查找成功" <<endl;
    // else cout << "查找失败" <<endl;

    // vector<int> vv = {1,2,3,4,5};
    // vector<int>::iterator it1= vv.begin();

    // *it1 = 8;
    // it1++;
    // *it1 = 7;

    // for(auto it2 = vv.cbegin();it2!=vv.end();it2++)         //auto关键字
    //     cout << *it2 << "\t";
    // cout << endl;

    // vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
    // //vector<int> v2(v1.begin()+2,v1.end()-3);
    // vector<int> v2 = {11,12,13,14,15,16,17,18,19,20};

    // //auto iter = v1.insert(v1.begin()+5,13);
    // auto iter = v1.insert(v1.begin()+5,v2.begin()+3,v2.begin()+8);
    // cout << "新插入的元素是:" << *iter <<endl; 

    // int i=0;
    // for(auto it2 = v1.cbegin();it2!=v1.end();it2++,i++)         //auto关键字
    //     {
    //         cout << *it2 << "\t";
    //         if((i+1)%5==0) cout <<endl;
    //     }
    // cout << endl;

    // for(auto it2 = v2.crbegin();it2!=v2.rend();it2++)         //auto关键字
    //     cout << *it2 << "\t";
    // cout << endl;

    vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};            //验证迭代器失效
    int i=0;
    for(auto it2 = v1.begin();it2!=v1.end();it2++,i++)         //auto关键字
        {
            cout << *it2 << "\t";
            if((i+1)%5==0) cout <<endl;
            //v1.erase(it2);        //擦除迭代器,迭代器失效
            it2 = v1.erase(it2);    //
        }
    cout << endl;
}
#include <iostream>
#include<list>

using namespace std;

int main()
{
    // list<int> la = {8,2,6,4,5};
    // for(auto& val: la)
    // {
    //     cout << val <<" ";
    // }
    // cout << endl;

    // la.reverse();       //反转

    // for(auto& val: la)
    // {
    //     cout << val <<" ";
    // }
    // cout << endl;

    // la.sort();          //排序

    // for(auto& val: la)
    // {
    //     cout << val <<" ";
    // }
    // cout << endl;

    // list<int> lb = {3,7,9,10,1};
    // lb.sort();

    // la.merge(lb);       //归并--需要都排序

    // for(auto& val: la)
    // {
    //     cout << val <<" ";
    // }
    // cout << endl;

    // list<int> l1 =lb;
    // if(l1!=lb)
    //     cout << "!=" <<endl;
    // else
    //     cout << "==" <<endl;

    // list<int> la = {8,2,6,4,5};
    // for(auto& val: la)
    // {
    //     cout << val <<" ";
    // }
    // cout << endl;

    // list<int> lb = {3,7,9,10,1};
    // for(auto& val: lb)
    // {
    //     cout << val <<" ";
    // }
    // cout << endl;

    // auto first = lb.begin();
    // first++;
    // auto last = lb.end();
    // last--;
    
    // la.splice(la.begin(),lb,first,last);
    // for(auto& val: la)
    // {
    //     cout << val <<" ";
    // }
    // cout << endl;

    // cout << "lb.size()=" << lb.size() <<endl;
    // for(auto& val: lb)
    // {
    //     cout << val <<" ";
    // }
    // cout << endl;

    list<int> la = {8,2,3,6,3,5,3,3,3,2,2,5};
    for(auto& val: la)
    {
        cout << val <<" ";
    }
    cout << endl;

    //la.remove(3);
    la.unique();

    for(auto& val: la)
    {
        cout << val <<" ";
    }
    cout << endl;
}

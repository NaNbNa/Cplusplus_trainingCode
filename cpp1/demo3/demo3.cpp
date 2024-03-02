#include <iostream>
#include <vector>
#include <list>
#include <algorithm>        //stl算法函数
#include <functional>       //stl仿函数
using namespace std;        //实现less和greater仿函数,实现sort函数(常常Vector使用)

template <class T>
class _less
{
public:
    bool operator()(const T& left, const T& right)
    {
        return left < right;
    }
};

template <class T>
class _greater
{
public:
    bool operator()(const T& left, const T& right)
    {
        return left > right;
    }
};

template <typename T>
bool compasc(const T& left,const T&right)
{
    // if(left<right) return true;
    // return false;
    return left < right;
}

template <typename T>
bool compdesc(const T& left,const T&right)
{
    // if(left>right) return true;
    // return false;
    return left > right;
}

template <typename T1,typename compare>
void bsort(const T1 first,const T1 last,compare comp)
{   
    bool bswap;
    while(true)
    {
        bswap = false;
        for(auto it = first;;)
        {
            auto left = it;
            it++;
            auto right = it;

            if(right==last) break;

            // if(*left > *right)       //过于简单粗暴
            if(comp(*left,*right)==true) continue;      //回调函数

            auto temp = *right;
            *right = *left;
            *left = temp;
            bswap = true;
        }
        if(bswap==false) break; 
    }
}
int main()
{
    vector<int> bh = {5,8,2,6,9,33,1,7,4};
    //list<string> bh = {"05","08","02","06","09","33","01", "07","04"};

    //bsort(bh.begin(),bh.end(),compdesc<int>);
    //bsort(bh.begin(),bh.end(),_less<string>());
    //bsort(bh.begin(),bh.end(),_greater<string>());
    //bsort(bh.begin(),bh.end(),_less<int>());
    //bsort(bh.begin(),bh.end(),_greater<int>());

    //bsort(bh.begin(),bh.end(),less<int>());           //stl提供的
    //bsort(bh.begin(),bh.end(),greater<int>());

    sort(bh.begin(),bh.end(),greater<int>());       //stl提供的
    //sort(bh.begin(),bh.end(),less<int>()); 

    for(auto& val : bh)
    {
        cout << val << " ";
    }
    cout <<endl;
}
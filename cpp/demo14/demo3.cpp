#include <iostream>
#include <string.h>

using namespace std;

//#define maxsize 10

                                //定长数组
// template <class T,int len>  //len是非通用类型参数
// class array1
// {
// private:
//     T items[len];
// public:
//     array1()
//     {
//         //memset(items,0,sizeof(items));    //限制在只存在基础类型,才可使用(不带指针)
//     }
//     ~array1(){}

//     T& operator[](int ii)
//     {
//         return items[ii];
//     }
//     const T& operator[](int ii) const
//     {
//         return items[ii];
//     }
// };
                                //变长数组
template <class T>  //len是非通用类型参数
class vertor1
{
private:
    int len;
    T* items;
public:
    
    vertor1(int size=10):len(size)
    {
        items = new T[len];
    }

    ~vertor1()
    {
        delete[] items; items = nullptr;
    }

    void resize(int size)
    {
        if(size<=len) return;

        T* temp = new T[size];
        for(int i =0;i<len;i++) temp[i] = items[i];

        delete[] items;
        items = temp;
        len =size;
    }

    int  size()
    {
        return len;
    }
    T& operator[](int ii)
    {
        if(ii>len-1) resize(ii+10);

        return items[ii];
    }
    const T& operator[](int ii) const
    {
        return items[ii];
    }
};
int main()
{
    // vertor1<int> aa;
    // aa[0]=5;aa[1]=15;aa[2]=12;aa[3]=3;aa[4]=14;

    // for(int i=0;i<5;i++)
    //     cout << "aa[" << i << "]=" << aa[i] <<endl;

    // array1<string,10> aa;       //string是类
    // aa[0]="西施";aa[1]="冰冰";aa[2]="西瓜";aa[3]="美眉";aa[4]="子都";

    // for(int i=0;i<5;i++)
    //     cout << "aa[" << i << "]=" << aa[i] <<endl;
    
    vertor1<int> aa(1);       //string是类
    //aa[0]="西施";aa[1]="冰冰";aa[2]="西瓜";aa[3]="美眉";aa[4]="子都";
    aa[0]=5;aa[1]=15;aa[2]=12;aa[3]=3;aa[4]=14;
    
    for(int i=0;i<5;i++)
        cout << "aa[" << i << "]=" << aa[i] <<endl;
}
#include <iostream>
#include <string>
#include <array>

using namespace std;

void func(int arr[][5],int len)
{
    for(int ii=0;ii<len;ii++)
    {
        for(int jj=0;jj<5;jj++)
        {
            cout << arr[ii][jj] << "\t";
        }
        cout <<endl;
    }
}

void func(const array<array<int,5>,10>& arr)
{
    for(int ii=0;ii<arr.size();ii++)
    {
        for(int jj=0;jj<arr[ii].size();jj++)
        {
            cout << arr[ii][jj] << "\t";
        }
        cout <<endl;
    }
}

template <typename T>
void func(const T& arr)
{
    for(int ii=0;ii<arr.size();ii++)
    {
        for(int jj=0;jj<arr[ii].size();jj++)
        {
            cout << arr[ii][jj] << "\t";
        }
        cout <<endl;
    }
}

int main()
{
    //int aa[10] = {1,2,3,4,5,6,7,8,9 ,10};         //前2种遍历
    // array<int,10> aa= {1,2,3,4,5,6,7,8,9 ,10};      //4种遍历

    // for(auto val:aa)
    //     cout << val <<"  ";
    // cout <<endl;

    // for(int ii=0;ii<10;ii++)
    //     cout << aa[ii] << "  ";
    // cout <<endl;

    // for(int ii=0;ii<aa.size();ii++)
    // {
    //     cout << aa[ii] << "  ";
    // }
    // cout <<endl;

    // for(auto it= aa.begin();it!=aa.end();it++)
    //     cout << *it << "  ";
    // cout <<endl;

    // int bb[10][5];      //二维数组
    // for(int ii=0;ii<10;ii++)
    // {
    //     for(int jj=0;jj<5;jj++)
    //         bb[ii][jj] = jj*10+ii;
    // }

    // func(bb,10);

    //array <array<int, 5>,10> bb;
    array <array<int, 6>,10> bb;
    for(int ii=0;ii<bb.size();ii++)
    {
        for(int jj=0;jj<bb[ii].size();jj++)
            bb[ii][jj] = jj*10+ii;
    }

    func(bb);
}
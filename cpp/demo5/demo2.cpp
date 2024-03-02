#include <iostream>

using namespace std;

int main()          //数组与指针的关系
{
    // char a;     //1byte
    // short b;    //2byte
    // int c;      //4byte
    // double d;   //8byte

    // cout << "a的地址是:" << (void*)&a <<endl;
    // cout << "a的地址+1是:" << (void*)(&a+1) <<endl;

    // cout << "b的地址是:" << (void*)&b <<endl;
    // cout << "b的地址+1是:" << (void*)(&b+1) <<endl;
    
    // cout << "c的地址是:" << (void*)&c <<endl;
    // cout << "c的地址+1是:" << (void*)(&c+1) <<endl;

    // cout << "d的地址是:" << (void*)&d <<endl;
    // cout << "d的地址+1是:" << (void*)(&d+1) <<endl;

    int a[5] = {3, 5, 8, 9, 0};

    // cout << "a的值是:" << (long long)a <<endl;
    // cout << "&a的值是:" << (long long)&a <<endl;

    // cout << "a[0]的地址是:" << (long long)&a[0] <<endl; 
    // cout << "a[1]的地址是:" << (long long)&a[1] <<endl; 
    // cout << "a[2]的地址是:" << (long long)&a[2] <<endl; 
    // cout << "a[3]的地址是:" << (long long)&a[3] <<endl; 
    // cout << "a[4]的地址是:" << (long long)&a[4] <<endl; 

    for(int i =0; i<5;i++)
        cout << "a[" << i <<"]的值是:" <<  a[i] <<endl;

    int* p =a;

    for(int i =0; i<5;i++)
        cout << "*(p+" << i <<")的值是:" <<  *(p + i) <<endl;

    // p ++ ;
    // a ++ ;  错误示范;a为常量

}
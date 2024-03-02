#include <iostream>
#include <string.h>

using namespace std;        //移动语义的问题--解决方案:完美转发

void func1(int& ii)
{
    cout << "参数是左值=" << ii <<endl;
}

void func1(int&& ii)
{
    cout << "参数是右值=" << ii <<endl;
}

// void func2(int&& ii)
// {
//     //func1(ii);      //不能传递移动语义
//     func1(move(ii));
// }

template <typename T>
void func2(T& ii)
{
    //func1(ii);      
    func1(ii);
}

template <typename T>
void func2(T&& ii)
{
    //func1(ii);      
    func1(move(ii));
}

template <typename T>       //完美转发
void func(T&& ii,int&& jj=9)
{
    func1(forward<T>(ii));
}

int main()
{
    int ii=3;
    // func2(ii);
    // func2(8);
    func(ii);
    func(8);
    //func(ii,ii);    //false,jj只可以接受右值
    func(8,8);
}
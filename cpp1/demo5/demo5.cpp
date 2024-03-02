#include <iostream>
#include <cassert>
using namespace std;                //断言,静态断言

void copydata(void* ptr1, void* ptr2)
{
    assert(ptr1&&ptr2);

    cout << "继续进行copydata(void* ptr1, void* ptr2)函数" <<endl;
}

int main()
{
    const int ii=0,jj=0;
    //copydata(&ii,&jj);

    //assert(ii);
    //static_assert(ii,"ii的值不合法");

    //copydata(nullptr,&jj);
}
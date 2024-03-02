#include <iostream>
using namespace std;    //namespace的用法:解决名称冲突
                        //using的作用域
#include "public.h"
#include "public1.h"

int main()
{
    // cout << "ab=" << aa::ab <<endl;
    // aa::func1();
    // aa::A1 a;
    // a.show();

    // using  aa::ab;
    // using  aa::func1;
    // using  aa::A1;
    // int ab=0;            //重声明
    // cout << "ab=" << ab <<endl;
    // func1();
    // A1 a1;
    // a1.show();

    // using namespace aa;
    // int ab=33;           //屏蔽aa中的ab
    // cout << "aa::ab=" << aa::ab <<endl;
    // cout << "ab=" << ab <<endl;
    // func1();
    // A1 a1;
    // a1.show();

    using namespace aa;
    using namespace bb;
    int ab=33;           //屏蔽aa中的ab
    cout << "aa::ab=" << aa::ab <<endl;
    aa::func1();
    aa::A1 a1;
    a1.show();
    cout << "bb::ab=" << bb::ab <<endl;
    
}
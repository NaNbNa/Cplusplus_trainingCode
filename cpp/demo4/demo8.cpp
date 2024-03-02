#include <iostream>

using namespace std;

void func(int* no, string* str)
{
    if(no== 0 || str == 0) return;
    cout << "亲爱的" << *no << "号 :" << *str <<endl;
}

int main()      //空指针
{
    // int* p = 0;  //0或NULL
    // //cout << "p = " << p << ", *p = " << *p <<endl;

    // delete p; 

    int* bh = 0;    //new int(3);
    string *message = 0;    //new string("你是一只傻傻鸟!");

    func(bh, message);

    delete bh;delete message;
} 
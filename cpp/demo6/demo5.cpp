#include <iostream>
#include <string.h>
using namespace std;

struct st_t     //带指针的结构体的清空
{
    int a;  //8
    int* p; //8
};
int main()
{
    st_t stt;
    memset(&stt, 0, sizeof(st_t));

    stt.a = 3;
    stt.p = new int[100];

    cout << "sizeof(stt) = " << sizeof(stt) <<endl;
    cout << "调用前:stt.a = " << stt.a << ", stt.p= " << (long long)stt.p <<endl;
    //memset(&stt, 0, sizeof(st_t));

    stt.a = 0;
    memset(stt.p, 0, sizeof(int));
    cout << "调用后:stt.a = " << stt.a << ", stt.p= " << (long long)stt.p <<endl;
    //cout << "stt.a = " << stt.a << ", stt.p= " << stt.p <<endl;
    delete[] stt.p;
}
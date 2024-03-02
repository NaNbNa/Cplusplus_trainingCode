#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char cc[8];             //8字节的内存空间
    strcpy(cc,"hello");
    cout << "cc=" << cc <<endl;


    int* a,*b;
    a = (int*)cc;          //8可以分配2个int
    //b = (int*)(cc+4);
    b = (int*)cc +1;    
    *a = 12345;
    *b = 54321;

    cout << "a=" << a <<endl;
    cout << "b=" << b <<endl;
    cout << "*a=" << *a <<endl;
    cout << "*b=" << *b <<endl;

    double* d = (double*)cc;    //8可以分配一个double
    *d = 12345.7;
    cout << "*d=" << *d <<endl<<endl;

    struct stt
    {
        int a;
        char b[4];
    }*st;

    st = (stt*)cc;
    st->a =38;
    strcpy(st->b,"abc");
    cout << "st->a=" << st->a <<endl;
    cout << "st->b=" << st->b <<endl;
    
    //void* malloc(size_t size)
    int* cc1 = (int*)malloc(8);
}
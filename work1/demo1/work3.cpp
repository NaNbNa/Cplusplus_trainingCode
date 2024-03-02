#include <iostream>
#include <string.h>
#include <chrono>
using namespace std;

char* mystrcpy(char* dest, const char* src)         //数组表示法
{
   size_t  i=0, j=0;       //4byte,可能比指针表示法快
   while(src[i])  
        dest[i++] = src[j++];
    dest[i] = 0;

    return dest;
}

char* mystrcpy1(char* dest, const char* src)        //指针表示法
{
    while(*src)
    {
        *dest++ = *src++;
    }

    *dest =0;
    return dest;
}
char* mystrcpy2(char* dest, const char* src)        //一次复制一整块内存
{
    memcpy(dest,src,strlen(src)+1);
    return dest;
}

char* mystrncpy(char* dest, const char* src ,const size_t n)
{
    size_t i =n;
    while(*src&&i-->0)
    {
        *dest++ = *src++;
    }
    while(*dest&&i-->0)
    {
        *dest++ = 0;
    }
    *dest = 0;
    return dest;
}

char* mystrncpy1(char* dest, const char* src ,const size_t n)
{
    size_t i =n;
    while(*src&&i-->0)
    {
        *dest++ = *src++;
    }
    while(i-->0)
    {
        *dest++ = 0;
    }
    *dest = 0;
    return dest;
}

int main()
{
    chrono::steady_clock::time_point start, end;        //计时变量
    chrono::nanoseconds dt;

    char dest[51];
    char dest1[51];
    char dest2[51];
    
    memset(dest,0,sizeof(dest));
    memset(dest1,0,sizeof(dest1));
    memset(dest2,0,sizeof(dest2));

    // start = chrono::steady_clock::now();
    // for(int i=0;i<10000000;i++)
    //     mystrcpy(dest,"abcdefghijklmnopqrstuvwxyz!");
    // cout << "dest = " <<"\t" << dest   <<endl;
    // end = chrono::steady_clock::now();
    // dt = end - start;
    // cout << "耗时:" << (double)dt.count()/(1000*1000*1000) << "秒!" <<endl;

    // start = chrono::steady_clock::now();
    // for(int i=0;i<10000000;i++)
    //     mystrcpy1(dest1,"abcdefghijklmnopqrstuvwxyz!");
    // cout << "dest1= " <<"\t" << dest1  <<endl;
    // end = chrono::steady_clock::now();
    // dt = end - start;
    // cout << "耗时:" << (double)dt.count()/(1000*1000*1000) << "秒!" <<endl;

    // start = chrono::steady_clock::now();
    // for(int i=0;i<10000000;i++)
    //     mystrcpy2(dest2,"abcdefghijklmnopqrstuvwxyz!");
    // cout << "dest2= " <<"\t" << dest2  <<endl;
    // end = chrono::steady_clock::now();
    // dt = end - start;
    // cout << "耗时:" << (double)dt.count()/(1000*1000*1000) << "秒!" <<endl;
    // //mystrncpy(dest1,"abcdefghijklmnopqrstuvwxyz!", 4);

    mystrncpy(dest,"abcdefghijklmnopqrstuvwxyz!",3);
    cout << "dest= " <<"\t" << dest   <<endl;
    //cout << "sizeof(size_t): " << sizeof(size_t) <<endl;
}
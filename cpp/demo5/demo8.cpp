#include <iostream>
#include <string.h>
using namespace std;

int main()  //二维数组,循环存储
{
    int bh[2][3];

    cout << "sizeof(bh) = " << sizeof(bh) <<endl;  //row*loc * 4(int)

    for(int row = 0;row <2;row ++)
    {
        for (int col = 0; col <3;col ++)
        {
            bh[row][col] = row*10 + col;
            cout << "bh[" << row << "][" << col <<"] = " << bh[row][col] <<endl;
            // cout << "&bh[" << row << "][" << col <<"] = " << &bh[row][col] <<endl;
        }
    }

    int* p = (int*)bh;
    //memset(bh,0,sizeof(bh));
    int bh1[6];
    memcpy(bh1, bh, sizeof(bh));        //把二维复制到一维

    for(int i=0; i < sizeof(bh1)/sizeof(int);i++)
    {
        cout << "bh1[" << i << "] =" << bh1[i] <<endl;
    }
    // for(int i=0; i < sizeof(bh)/sizeof(int);i++)
    // {
    //     cout << "p[" << i << "] =" << p[i] <<endl;
    // }
    int aa = 8;
    int b[aa][aa+2];
    int c[sizeof(aa)/2];

    cout << "ok"<< endl;
}
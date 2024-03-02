#include <iostream>
#include <string.h>

using namespace std;

int main()      //一维数组的使用
{
    int bh[] = {1, 2, 3, 12, 32, 23, 35, 65};
    string name[3];

    // bh[0] = 0; bh[1] =1; bh[2] =2;

    cout << "sizeof(bh) = " << sizeof(bh) <<endl;

    for(int ii=0;ii<3;ii++)
        bh[ii] = 30 + ii;

    //memset(bh,0,sizeof(bh)); //清零
    int bh1[sizeof(bh)/sizeof(int)];
    memcpy(bh1, bh, sizeof(bh));

    for(int ii=0;ii<sizeof(bh1)/sizeof(int);ii++)
        cout << "bh1[" << ii << "] = " << bh1[ii] <<endl;

    
 }
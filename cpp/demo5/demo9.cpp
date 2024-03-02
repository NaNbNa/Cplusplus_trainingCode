#include <iostream>

using namespace std;

//void func(int (*p)[3], int len)
void func(int p[][3], int len)
{
    for(int row = 0; row < len;row ++)
    {
        for (int col = 0;col <3;col ++)
        {
            cout << "p[" << row << "]" << "[" << col << "] = "  << p[row][col] << "\t";
        }
        cout <<endl;
    }

}
int main()              //行指针的用法
{
    // int a[10];

    // cout << "数组a的第0个元素的地址是:" << a <<endl;
    // cout << "数组a的地址是:" << &a <<endl;

    // cout << "数组a的第0个元素的地址+1是:" << a+1 <<endl;
    // cout << "数组a地址是:" << &a +1 <<endl;

    // int* p =a;
    // //int* p = &a; 
    // int (*p2)[10] = &a;

    // int bh[2][3];

    // //int* p =bh;
    // int (*p)[3] = bh;

    int bh[2][3] = {2, 3, 6, 7, 1, 33};
    func(bh,2);
}
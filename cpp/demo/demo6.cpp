#include <iostream>

using namespace std;

int main()  //嵌套循环          do-while 循环
{
    // for (int i = 1;i <= 4; i++)  //4个小组,每个小组3个超女
    // {
    //     for (int j =1; j <=3;j++)
    //     {
    //         cout << "这是第" << i << "小组的第" << j << "个超女!" <<endl;
    //     }
    // }

    //  for (int i = 1;i <= 9; i++)     //九九乘法表
    // {
    //     for (int j =1; j <=i;j++)
    //     {
    //         cout <<  i << "*" << j << "=" << i*j << " ";
    //     }
    //     cout << endl;
    // }
    
    int tag = 1;
    do
    {
        /* code */
        cout << "这是第" << tag << "名超女的编号" << endl;
    } while (tag++ <=10);
    
     
}
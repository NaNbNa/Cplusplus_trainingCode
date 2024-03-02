#include <iostream>

using namespace std;

int main()          //堆上动态分配内存,处理大量数据更方便,不容易出错
{
    // int* arr = new int[8];
    
    // for (int i=0;i<8;i++)
    // {
    //     arr[i] = 100 +i;
    //     cout << "arr[" << i << "] = " << arr[i] <<endl;
    // }

    // delete[] arr;

    int a[100000001];  //直接分配
    //int* aa = new int[1000000000000]; //堆上动态分配,失败程序崩溃
    int* aa = new (std::nothrow) int[1000000000]; //堆上动态分配,失败返回空指针
    if( aa== nullptr)
        {
            cout << "false!";     //分配失败
        }
    else
         {
            a[1000] = 8;
            delete[] aa;

         }
}
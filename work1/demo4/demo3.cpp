#include <iostream>
#include <string.h>

using namespace std;

void bubblesort1(int arr[],const int len)
{
    if(arr==0||len<2) return;

    bool ifswap = false;        //是否发生交换
    int temp=0;
    for(int i=0;i<len;i++)
    {
        ifswap = false;
        for(int j=0;j<len-i-1;j++)
        {
            if( arr[j] > arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1]= arr[j];
                arr[j] = temp;
                ifswap = true;
            }
        }
        if(!ifswap) break;
    }
}
int main()
{
    int arr[] = { 44,3,38,5,47,15,36,26,27,2,46,4,19,50,48 };   // 待排序的数组。
    int len = sizeof(arr) / sizeof(int);    // 求数组长度

    cout << "before sort:" <<endl;
    for(int i=0;i<len;i++) 
    {
        cout << "arr[" << i << "]=" << arr[i] << "  ";
        if((i+1)%5==0) cout <<endl;
    }
    cout <<endl;

    cout << "after sort:" <<endl;
    bubblesort1(arr,len);
    for(int i=0;i<len;i++) 
    {
        cout << "arr[" << i << "]=" << arr[i] << "  ";
        if((i+1)%5==0) cout <<endl;
    }
    cout <<endl;
}
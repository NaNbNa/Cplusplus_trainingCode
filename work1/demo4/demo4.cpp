#include <iostream>
#include <string.h>

using namespace std;        //获取最小值是arr[min] > arr[j],不是arr[i] > arr[j]i

void selectsort1(int arr[], const int len) 
{
    if(arr==0||len<2) return;

    int min =0;
    int temp=0;

    for(int i=0;i<len-1;i++)
    {
        min =i;
        for(int j=i+1;j<len;j++)
        {
            if(arr[min] > arr[j]) min =j;
        }

        if(min!=i)
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }

}
int main()
{
    int arr[] = { 44,3,38,5,47,15,36,26,27,2,46,4,19,50,48 };   // 待排序的数组。
    int len = sizeof(arr) / sizeof(int);    // 求数组长度。

    cout << "before sort:" <<endl;
    for(int i=0;i<len;i++) 
    {
        cout << "arr[" << i << "]=" << arr[i] << "  ";
        if((i+1)%5==0) cout <<endl;
    }
    cout <<endl;

    cout << "after sort:" <<endl;
    selectsort1(arr,len);
    for(int i=0;i<len;i++) 
    {
        cout << "arr[" << i << "]=" << arr[i] << "  ";
        if((i+1)%5==0) cout <<endl;
    }
    cout <<endl;
}
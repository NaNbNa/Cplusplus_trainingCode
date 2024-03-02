#include <iostream>
#include <string.h>

using namespace std;
void quicksort(int arr[], int len)                  //先动右指针,后动左指针
{
    if(arr==0||len<2) return;           //deal param

    int mid = arr[0];
    int l = 0, r =len-1;

    while(l<r)                  //$arr;     l,r,empty
    {
        while(arr[r] >= mid&&l<r) r--;              

        if(l<r)     //arr[r] < mid
        {
            arr[l] =arr[r];
            l++;     //update l
        }

        while(arr[l] <= mid&&l<r) l++;

        if(l<r)     //arr[l] > mid
        {
            arr[r] =arr[l];   
            r--;           //update r
        }
    }   //l==r
    arr[l] = mid;
    
    quicksort(arr,l);
    quicksort(arr+r+1,len-1-r);
}
int main()
{
    int arr[] = { 44,3,38,5,47,5,36,26,27,2,46,4,19,50,48 };   // 待排序的数组。
    int len = sizeof(arr) / sizeof(int);    // 求数组长度。

    cout << "\t\t\t\tquicksort" <<endl;
    cout << "before sort:" <<endl;
    for(int i=0;i<len;i++) 
    {
        cout << "arr[" << i << "]=" << arr[i] << "\t";
        if((i+1)%5==0) cout <<endl;
    }
    cout <<endl;

    cout << "after sort:" <<endl;
    quicksort(arr,len);
    for(int i=0;i<len;i++) 
    {
        cout << "arr[" << i << "]=" << arr[i] << "\t";
        if((i+1)%5==0) cout <<endl;
    }
    cout <<endl;
}
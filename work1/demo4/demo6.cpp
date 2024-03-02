#include <iostream>
#include <string.h>

using namespace std;
void shellsort(int arr[], const int len)
{
    if(arr==0||len<2) return;       //deal param

    int group = len/2;
    int temp=0,start=0;  // start:group's first one

    while(group>0)      //$arr;  group, start
    {   
        start =0;               
        while(start<group)    //all groups
        {                      //$start, i, j
            for(int i=start+group;i<len;i+=group)     //one group:insertsort
            {
                temp = arr[i];

                int j=i-group;
                for(;j>=0;j-=group)
                {
                    if(arr[j] <= temp) break;

                    arr[j+group] = arr[j];
                } 
                arr[j+group] = temp;
            }

            start++;
        }   //start = group

        group /= 2;  //update group;
    }
}
int main()
{
    int arr[] = { 44,3,38,5,47,5,36,26,27,2,46,4,19,50,48 };   // 待排序的数组。
    int len = sizeof(arr) / sizeof(int);    // 求数组长度。

    cout << "\t\t\t\tshellsort" <<endl;
    cout << "before sort:" <<endl;
    for(int i=0;i<len;i++) 
    {
        cout << "arr[" << i << "]=" << arr[i] << "\t";
        if((i+1)%5==0) cout <<endl;
    }
    cout <<endl;

    cout << "after sort:" <<endl;
    shellsort(arr,len);
    for(int i=0;i<len;i++) 
    {
        cout << "arr[" << i << "]=" << arr[i] << "\t";
        if((i+1)%5==0) cout <<endl;
    }
    cout <<endl;
}
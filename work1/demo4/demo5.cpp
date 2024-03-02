#include <iostream>
#include <string.h>

using namespace std;
void insertsort1(int arr[],const int len)
{
    if(arr==0||len<2) return;

    int temp=0;
    int pos =0;         //swap
    for(int i=1;i<len;i++)
    {
        temp = arr[i];
        
        pos =i;
        int j=i-1;
        for(;j>=0;j--,pos--)      //pos=j+1
        {
            if(temp>=arr[j]) break;

            arr[pos] = arr[pos-1];  //swap
        }       //pos=j+1

        if(j!=i-1)  arr[pos] =temp;
    }

}
int main()
{
        int arr[] = { 44,3,38,5,47,5,36,26,27,2,46,4,19,50,48 };   // 待排序的数组。
    int len = sizeof(arr) / sizeof(int);    // 求数组长度。

    cout << "\t\tinsertsort" <<endl;
    cout << "before sort:" <<endl;
    for(int i=0;i<len;i++) 
    {
        cout << "arr[" << i << "]=" << arr[i] << "\t";
        if((i+1)%5==0) cout <<endl;
    }
    cout <<endl;

    cout << "after sort:" <<endl;
    insertsort1(arr,len);
    for(int i=0;i<len;i++) 
    {
        cout << "arr[" << i << "]=" << arr[i] << "\t";
        if((i+1)%5==0) cout <<endl;
    }
    cout <<endl;
}
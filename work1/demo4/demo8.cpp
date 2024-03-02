#include <iostream>
#include <string.h>

using namespace std;
void arrminmax(int arr[],int len, int* minvalue,int* maxvalue)
{
    if(arr==0||len<1) return;

    int min =0, max =0;       //index

    for(int i=1;i<len;i++)
    {
        if(arr[i] < arr[min])  min =i;
        if(arr[i] > arr[max])  max =i;
    }
    *minvalue = arr[min];
    *maxvalue = arr[max];
}

void countsort(int arr[], int len)
{
    if(arr==0||len<2) return ;

    int min, max;
    min = max =0;
    arrminmax(arr,len,&min,&max);

    int len1 = max -min+1;
    int* arr1 = new int[len1];        //使用动态分配更好
    memset(arr1,0,sizeof(int)*len1);

    for(int i=0;i<len;i++)      //count
        arr1[arr[i]-min] ++;
    
    for(int i=0,j=0;i<len1;i++)      
    {
        while(arr1[i]>0&&j<len)     //$arr1, arr; i, j
        {
            arr[j] = i+min;
            j++;            //update j
            arr1[i] --;     //update arr1
        }
    }

    delete[] arr1;
}
int main()
{
    int arr[] = { -2,3,8,7,1,2,2,2,7,3,9,8,2,1,4,2,4,6,9,2 }; // 待排序的数组。
    int len = sizeof(arr) / sizeof(int);    // 求数组长度。

    cout << "\t\t\t\tcountsort" <<endl;
    cout << "before sort:" <<endl;
    for(int i=0;i<len;i++) 
    {
        cout << "arr[" << i << "]=" << arr[i] << "\t";
        if((i+1)%5==0) cout <<endl;
    }
    cout <<endl;

    cout << "after sort:" <<endl;
    countsort(arr,len);
    for(int i=0;i<len;i++) 
    {
        cout << "arr[" << i << "]=" << arr[i] << "\t";
        if((i+1)%5==0) cout <<endl;
    }
    cout <<endl;
}
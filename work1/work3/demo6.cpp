#include <iostream>
#include <string.h>
using namespace std;
void minmax(int arr[],int len, int& min, int& max)
{
    if(len<1) return;

    min = max =arr[0];
    for(int ii=0;ii<len;ii++)
    {
        if(arr[ii]> max) max =arr[ii];
        if(arr[ii]< min) min = arr[ii];
    }
}
void countSort(int arr[],int len)
{
    if(len <2) return;

    int min,max;
    minmax(arr,len,min,max);
    int len1 = max-min+1;

    int* counter = new(std::nothrow) int[len1];
    if(counter==nullptr) return;
    memset(counter,0,sizeof(int)*len1);

    for(int ii=0;ii<len;ii++)
    {
        counter[arr[ii]-min]++;
    }

    int pos=0;
    for(int ii=0;ii<len1;ii++)
    {
        while(counter[ii]>0)
        {
            arr[pos++] = ii+min;
            counter[ii]--;
        }
    }

    delete[] counter;
}
int main()
{
    cout << "countSort" <<endl;
    int arr[] = {2,3,8,7,1,2,2,2,7,3,9,8,2,1,4,2,4,6,9,2};
    int len = sizeof(arr)/sizeof(int);

    cout <<"排序前:" <<endl;
    for(int ii=0;ii<len;ii++)
    {
        cout << arr[ii] <<"  ";
    }
    cout <<endl;

    countSort(arr,len);

    cout <<"排序后:" <<endl;
    for(int ii=0;ii<len;ii++)
    {
        cout << arr[ii] <<"  ";
    }
    cout <<endl;
}
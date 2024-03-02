#include <iostream>
using namespace std;    

void groupSort(int arr[], int len, int start, int step) //插入排序
{
    int temp;

    for(int ii=start+step;ii<len;ii=ii+step)
    {
        temp = arr[ii];
        int jj = ii-step;
        for(;jj>=0;jj = jj -step)
        {
            if(arr[jj]<=temp)  break;

            arr[jj+step] = arr[jj];
        }
        if(jj!=ii-step)
            arr[jj+step] =temp;
    }
}
void shellSort(int arr[],int len)
{
    if(len<2) return;

    for(int step=len/2;step>=1;step = step/2)
    {
        for(int start=0;start<step;start++)
        {
            groupSort(arr,len,start,step);
        }
    }
}
int main()
{
    cout << "shellSort" <<endl;
    int arr[] = {44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
    int len = sizeof(arr)/sizeof(int);

    cout <<"排序前:" <<endl;
    for(int ii=0;ii<len;ii++)
    {
        cout << arr[ii] <<"  ";
    }
    cout <<endl;

    shellSort(arr,len);

    cout <<"排序后:" <<endl;
    for(int ii=0;ii<len;ii++)
    {
        cout << arr[ii] <<"  ";
    }
    cout <<endl;
}
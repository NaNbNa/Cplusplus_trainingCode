#include <iostream>
using namespace std;

void insertSort(int arr[], int len)
{
    if(len<2) return;

    int temp;
    for(int ii=1;ii<len;ii++)
    {
        temp = arr[ii];
        int jj=ii-1;
        for(;jj>=0;jj--)
        {
            if(arr[jj] <= temp) break;

            arr[jj+1] = arr[jj];    //后移
        }
        if(jj!=ii-1)
        {
            arr[jj+1] = temp;
        }
    }  
}

int main()
{
    cout << "insertSort" <<endl;
    int arr[] = {44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
    int len = sizeof(arr)/sizeof(int);

    cout <<"排序前:" <<endl;
    for(int ii=0;ii<len;ii++)
    {
        cout << arr[ii] <<"  ";
    }
    cout <<endl;

    insertSort(arr,len);

    cout <<"排序后:" <<endl;
    for(int ii=0;ii<len;ii++)
    {
        cout << arr[ii] <<"  ";
    }
    cout <<endl;
}

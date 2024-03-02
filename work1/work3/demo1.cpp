#include <iostream>
#include <string.h>

using namespace std;
void bubbleSort(int arr[], int len)
{
    if(len<2) return;

    bool ifswap;
    int temp;
    for(int ii=0;ii<len-1;ii++)
    {
        ifswap = false;
        for(int jj=1;jj<len-ii;jj++)
        {
            if(arr[jj] < arr[jj-1])   //升序
            {
                ifswap = true;
                temp = arr[jj];
                arr[jj] = arr[jj-1];
                arr[jj-1] = temp;
            }
        }
        if(ifswap==false) break;
    }
}

int main()
{
    int arr[] = {44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
    int len = sizeof(arr)/sizeof(int);

    cout <<"排序前:" <<endl;
    for(int ii=0;ii<len;ii++)
    {
        cout << arr[ii] <<"  ";
    }
    cout <<endl;

    bubbleSort(arr,len);

    cout <<"排序后:" <<endl;
    for(int ii=0;ii<len;ii++)
    {
        cout << arr[ii] <<"  ";
    }
    cout <<endl;
}
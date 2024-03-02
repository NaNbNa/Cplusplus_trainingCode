#include <iostream>

using namespace std;

void quickSort(int arr[], int len)
{
    if(len<2) return;

    int left = 0, right = len-1;
    int temp = arr[0];

    while(left<right)
    {
        while(arr[right]>=temp&&left<right) right--;
        if(left<right)
        {
            arr[left] = arr[right];
            left++;
        }

        while(arr[left]<=temp&&left<right) left++;
        if(left<right)
        {
            arr[right] = arr[left];
            right--;
        }
    }       //left == right
    arr[left] = temp;

    quickSort(arr,left);
    quickSort(arr+left+1,len-left-1);
}

int main()
{
    cout << "quickSort" <<endl;
    int arr[] = {44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
    int len = sizeof(arr)/sizeof(int);

    cout <<"排序前:" <<endl;
    for(int ii=0;ii<len;ii++)
    {
        cout << arr[ii] <<"  ";
    }
    cout <<endl;

    quickSort(arr,len);

    cout <<"排序后:" <<endl;
    for(int ii=0;ii<len;ii++)
    {
        cout << arr[ii] <<"  ";
    }
    cout <<endl;
}
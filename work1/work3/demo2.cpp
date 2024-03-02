#include <iostream>
using namespace std;    //优化过的选择排序

void selectSort(int arr[], int len)
{
    if(len<2) return ;

    int minpos, maxpos ,temp;
    int left =0, right = len-1;
    while(left<right)
    {
        minpos =left;
        maxpos =right;
        for(int jj=left;jj<=right;jj++) //选出最大值和最小值
        {
            if(arr[jj] < arr[minpos])
            {
                minpos = jj;
            }
            if(arr[jj] > arr[maxpos])
            {
                maxpos = jj;
            }
        }
        //把选出的最大和最小值进行交换,插入合适的位置
        if(minpos!=left)
        {
            temp = arr[left];
            arr[left] = arr[minpos];
            arr[minpos] = temp;
        }

        if(maxpos!=right)
        {
            temp = arr[right];
            arr[right] = arr[maxpos];
            arr[maxpos] = temp;
        }

        left++;
        right--;
    }
}

int main()
{
    cout << "selectSort" << endl;
    int arr[] = {44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
    int len = sizeof(arr)/sizeof(int);

    cout <<"排序前:" <<endl;
    for(int ii=0;ii<len;ii++)
    {
        cout << arr[ii] <<"  ";
    }
    cout <<endl;

    selectSort(arr,len);

    cout <<"排序后:" <<endl;
    for(int ii=0;ii<len;ii++)
    {
        cout << arr[ii] <<"  ";
    }
    cout <<endl;
}
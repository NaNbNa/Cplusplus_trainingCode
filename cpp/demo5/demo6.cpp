#include <iostream>

using namespace std;        //折半查找

int search(int arr[],int len,int key)
{
    int low = 0, high = len-1,mid;
    
    while(low <= high)
    {
        mid = (low +high)/2;

        if(arr[mid]== key)  return mid;
        else if(arr[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main()
{
    int a[10] = {7, 9, 12, 16, 21, 25, 30, 41, 48};

    int key;

    cout << "key = ";
    cin >> key;

    if(search(a,10,key)>=0) cout << "数组a中有key = " << key << endl;
    else cout << "数组a中没有key = " << key << endl;

}
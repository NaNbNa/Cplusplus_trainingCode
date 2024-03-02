#include <iostream>

using namespace std;


void func(int arr[]) //int* arr
{
    cout << "sizeof(arr) = " << sizeof(arr) << endl;
    for(int i= 0; i< sizeof(arr)/sizeof(int);i++)
    {
        cout << "arr[" << i << "] = " << arr[i] <<endl;
    }
}
int main()          //数组的越界和做参数
{
    int a[5] ={3, 6, 5, 8, 9};

    cout << "sizeof(a) = " << sizeof(a) <<endl;

    func(a);
    // for(int i=0;i <5;i++)
    // {
    //     cout << "a[" << i << "] = " << a[i] <<endl;
    // }

    // int *p = a;
    // for (int i=0; i< 5;i++)
    // {
    //     cout << "*(p+" << i << ") = " << *(p + i) <<endl;
    //     cout << "p[" << i << "] = " << p[i] <<endl;
    // }
    // cout << (&a[2])[0] << endl;  //5
}
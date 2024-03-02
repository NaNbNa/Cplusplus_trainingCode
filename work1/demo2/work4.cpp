#include <iostream>
#include <string.h>

using namespace std;

void rrand(int arr[], const int len, const int minvalue=0)
{
    if(arr==0) return;
    
    srand(time(0));

    int i= 0; 
    int temp=0;

    while(i<len)
    {
        temp =rand()%len+minvalue;

        int j=0;
        for(j=0;j<i;j++)
            if(arr[j]==temp)
            {
                break;
            }
           
        if(i==j) 
        {
            arr[i] =temp;
            i++;
        }
    }
}

void rrand1(int arr[], const int len, const int minvalue=0)
{
    if(arr==0) return;
    
    srand(time(0));

    for(int i=0;i<len;i++)
    {
        while(true)
        {
            int temp=rand()%10+minvalue;
            int j=0;
            for(j=0;j<i;i++)
            {
                if(temp==arr[j]) break;
            }
            if(i=j)
                arr[i] = temp; break;
        }
    }
}

int main()
{
    int len = 100;
    int min =0;
    int arr[len];
    memset(arr,0,sizeof(arr));

    rrand(arr,len,min);
    for(int i=0;i<len;i++)
    {
        cout << "arr[" << i << "]=" << arr[i] <<"\t" ;
        if((i+1)%5==0) cout <<endl;
    }
}
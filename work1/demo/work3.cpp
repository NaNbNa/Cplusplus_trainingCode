#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int i =1, sum=0;
    // while(i<=100)
    // {
    //     sum +=i;
    //     i++;
    // }
    // cout << "1+2+3+...+99+100,sum = " << sum <<endl;

    for( ;sum <=5000; sum +=i)
    {
        cout << "当前sum =" << sum << endl;
        cout <<"请输入数值i:" ;
        cin >> i; 
    }
     cout << "最终sum =" << sum << endl;
}
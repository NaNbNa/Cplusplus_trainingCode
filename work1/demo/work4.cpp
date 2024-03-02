#include <iostream>

using namespace std;

int main()
{
    int num =0, sum =0;
    bool jx =true;
    // while(jx)
    // {
    //     cout << "sum = " << sum <<endl;
    //     cout << "请输入数值:" ; cin >> num;
    //     if(num>=1 &&num <=100) sum += num;
    //     else if(num==0) jx = num;
    //     else continue;
    // }
    // cout << "sum = " << sum <<endl;

    cout << "能被五整除的数:" <<endl;
    for(int i=1;i<=100;i++)
       {
            if(i%5==0)
                cout << i << "\t";
            if(i%50==0)
                cout << endl;
       }
}
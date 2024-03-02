#include <iostream>

using namespace std;

int f(int x)
{
    if (x == 0) return 0;

    return x + f(x-1);
}

int main()
{
    int num = 3;
    cout << "f(" << num << ") = " << f (num) <<endl;

    int sum = 0;
    for (int i= 1; i<= 100;i++)
    {
        sum += i;
    }

    cout << "sum = " << sum <<endl;
}
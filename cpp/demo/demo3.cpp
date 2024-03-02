#include <iostream>

using namespace std;

int main()          //三目运算
{
    // int a = 17, b = 19, c = 10, d;

    // 比较 a, b, c大小的值,将较大值放入d中
    // d =  (a > b ? a : b) > c ? (a > b ? a : b): c ;

    // if (a>b) c = a;
    // else c = b;

    // cout << " d = " << d << endl;

    int year;    //判断是否是闰年,不适用数值很大的年份
    cout << "请输入年份:";
    cin >> year;
    bool rn ;
    rn = (year % 100 ==0)?(year % 400 == 0? 1:0):(year % 4  ==0?1:0);

    if (rn) cout << year << "年是闰年!" << endl;
    else cout << year << "年不是闰年!" << endl;
    
}
#include <iostream>

using namespace std;

int main()      //swith语句--不能使用字符串,只能字符和整形数据
{
    int sc;
    cout << "输入超女的身材:";
    cin >> sc;
    switch (sc)
    {
        case 1: cout << "火辣!" << endl;  break;
        case 2: cout << "丰满!" << endl;  break;
        case 3: cout << "苗条!" << endl;  break;
        case 4: cout << "强壮!" << endl;  break;
        case 5: cout << "肥胖!" << endl;  break;
        default:cout << "未知!" << endl;
    }
}
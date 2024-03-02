#include <iostream>

using namespace std;

int main()          //枚举
{
    enum colors  {red =0, yellow = 1, blue = 2 ,other = 3 };

    colors cc1 = red;
    colors cc = (colors)1;
    // int 型
    cout << "red= " << red << ", yellow= " << yellow 
    << ", blue= " << blue << ", other= " << other <<endl;

    switch(cc)
    {
        case red:   cout << "红色!" << endl; break;
        case yellow: cout << "黄色!" <<endl; break;
        case blue: cout << "蓝色!" <<endl;  break;
        default: cout << "unkown!" << endl; 
    }
}
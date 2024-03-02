#include <iostream>

using namespace std;

int main()          //if 多层逻辑语句
{
    int age = 25;
    int height = 170;
    string sc = "火辣";
    string yz = "漂亮";
    
    if (age > 20 && age < 30)
    {
        if ( height > 165 && height <175)
        {
            if (sc == "火辣")
            {
                if (yz == "漂亮" || yz == "一般")
                            {
                                cout << "晋级成功!" << endl;
                            }
                            else
                            cout << "颜值不够！" << endl;
            }
            else 
            cout << "身材不好！" << endl;   
        }
        else 
        cout << "身高不合格!"  << endl;
    }
    else 
    cout << "年龄不及格!" << endl;
}
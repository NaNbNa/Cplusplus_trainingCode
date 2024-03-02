#include <iostream>

using namespace std;

int main()      //if 语句
{
    bool yz ;       //颜值
    char sex ;      //性别
    int sc;         //身材
    
    cout << "请输入超女的性别(1-男,0-女）：";
    cin >> sex;
    if (sex == '0')
    {
        cout << "请输入超女的颜值(1--beauty ,0-not beauty): " ;
        cin >> yz ;
        if (yz)
        {   
            cout << "晋级！" << endl;
            cout << "下一级:请输入超女的身材(1--火辣,2-苗条,3-丰满,4-强壮,5-肥胖):";
            cin >> sc;
            if (sc == 1)
            {
                cout << "晋级,你已经成为超女!"<< endl;
            }
            else if (sc == 2)
            {
                cout << "待定,你还有其他非常好的选择!" << endl;
            }
            else if (sc == 3)
            {
                cout << "很棒!超女中的超女!" << endl;
            }
            else if (sc == 4)
            {
                cout << "强壮?不不,想要软弱的!" << endl;
            }
            else if (sc == 5)
            {
                cout << "tank为什么要来这里?失败!" << endl;
            }
            else 
            {
                 cout << "未知身材?你失败了!" << endl;
            }
        }
        else
        {
            cout << "抱歉回家！" << endl;
            cout << "推荐一个美容院" << endl;
        }
    }
        else 
    {
        cout << "男的做什么超女,应该是超男" << endl;
    }
}

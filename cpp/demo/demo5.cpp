#include <iostream>

using namespace std;

int main()      //循环语句while,for,do-while
{
    // int tag = 1;
    // while(tag <= 10)
    // {
    //     cout << "这是第" << tag++ << "名超女的编号!" << endl;
    // }

    // bool yz;    //颜值
    // bool sc;    //身材
    // bool jx;    //继续
    // int i =0;

    // //重点--存在循环bug,当输入不是数字时,出现错误,跳过后面的所有选项并打印出来.
    // //并不断循环,如果未加i控制,则是无限循环
    // while (i++< 10)                                                     
    // {
    //     cout << "请输入超女的颜值(1-漂亮):";
    //     cin >> yz;
        
    //     if (yz) cout << "晋级成功" << endl;
    //     else
    //     {
    //         cout << "请输入超女的身材(1-火辣):" ;
    //         cin >> sc;
    //         if (sc) cout << "晋级成功!" << endl;
    //         else cout << "失败!" << endl;
            
    //     }

    //     cout << "是否继续选秀(1-继续):" ;
    //     cin >> jx;
    //     if (!jx) break;
    // }
    for (int tag =1;tag<10;tag++)
    {
        cout << "这是第" << tag << "个超女的编号!" << endl;
    }
}
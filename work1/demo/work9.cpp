#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    //任务1
    // double girls[3][4];
    // memset(girls,0,sizeof(girls));

    // double group[3], all=0;
    // memset(group,0,sizeof(group));
    // double temp;        //暂时存放接受值

    // for(int row=0;row <3;row++)
    // {
    //     for(int col=0;col<4;col++)
    //     {
    //         cout<< "请输入第" << row+1 <<"组,第" << col+1 << "名超女的体重:" ;
    //         cin >> temp;
    //         girls[row][col] = temp;

    //         group[row] +=temp;  //计算两个总和
    //         all +=temp;
    //     }
    // }

    // for(int row=0;row<3;row++)
    //     cout << "第" << row+1 << "组的超女的平均体重是:" << group[row]/4 << "\t";
    // cout <<endl;
    // cout << "全部超女的平均体重是 :" << all/12 <<endl;

    //任务2
    char name[3][11];
    memset(name,0,sizeof(name));

    for(int i=0;i<3;i++)
    {
        cout << "第" << i << "个超女的姓名是:" ;
        cin >> name[i];
    }

    for(int i=0;i<3;i++)
    {
        cout << "亲爱的" << name[i] << ":你是一只傻傻鸟!"  <<endl;
    }
    
}

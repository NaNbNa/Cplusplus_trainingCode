#include <iostream>
#include <string.h>
using namespace std;

struct st_girl {
        int age;
        int height;
        //string sc;     // C++风格字符串。
        char sc[31];  // C风格字符串。
        bool yz;	// true-漂亮；false-一般。
    } stgirl;

int main()
{
    bool jx = true; //进入选秀
    //stgirl.sc = "0"; //初始化为0,string类
    memset(stgirl.sc,0,sizeof(stgirl.sc));  //char类初始化
    //cout << "sc = " << stgirl.sc <<endl;
    stgirl.age = 0; stgirl.height = 0; 
    stgirl.yz = 0;


    while(jx)  //选秀开始
    {
        cout << "请输入一位超女的全部数据:" <<endl;
        cout << "年龄:" ;
        cin >> stgirl.age;
         cout << "身高(cm):" ;
        cin >> stgirl.height;
         cout << "身材:" ;
        cin >> stgirl.sc;
         cout << "颜值(1-漂亮,0-一般):" ;
        cin >> stgirl.yz;
        cout << "age=" << stgirl.age << ", height=" <<stgirl.height << 
        ", sc=" <<  stgirl.sc << ", yz= " <<stgirl.yz <<endl;
        cout << "输入完毕!" <<endl;

        if ((stgirl.age > 18   && stgirl.age <25)     &&
           (stgirl.height >165 && stgirl.height <178) &&
           //(stgirl.sc=="火辣")                          && 
           (strcmp(stgirl.sc,"火辣")==0)                    &&
           (stgirl.yz))
           {
            cout << "这是妃子!" <<endl;
           }
        else if ((stgirl.age > 18   && stgirl.age <30)     &&
                (stgirl.height >160 && stgirl.height <165) &&
                //(stgirl.sc=="火辣"   ||  stgirl.sc == "普通") &&
                (strcmp(stgirl.sc,"火辣")==0|| strcmp(stgirl.sc,"普通")==0)&&
                (stgirl.yz))
                {
                    cout << "这是宫女!" <<endl;
                }
        else if((stgirl.age > 35    && stgirl.age <40)     &&
                (stgirl.height >0155 && stgirl.height <165) &&
                //(stgirl.sc=="飞机场" || stgirl.sc == "普通") &&
                (strcmp(stgirl.sc,"飞机场")==0 || strcmp(stgirl.sc,"普通")==0)&&
                (!stgirl.yz))
                {
                    cout << "这是嬷嬷!" <<endl;
                }
        else
        {
            cout << "啥都不是!" <<endl;
        }
    cout << "是否继续选秀?(1-继续,0-停止:)";
    cin >> jx;
    }
}
#include <iostream>
using namespace std;

#include "boy.h"
#include "girl.h"
//#define BH 3
//#define MES "你是一只傻傻鸟"
int main()
{
    // cout << BH  << "," << MES;
    // cout << 3  << "," << "你是一只傻傻鸟";

    // cout << "当前源代码的文件名:__FILE__=" << __FILE__ <<endl;
    // cout << "当前源代码函数名:__FUNCTION__=" << __FUNCTION__ <<endl;
    // cout << "当前源代码行数:__LINE__=" << __LINE__ <<endl;
    // cout << "编译的日期:__DATE__=" << __DATE__ <<endl;
    // cout << "编译的时间:__TIME__=" << __TIME__ <<endl;
    // cout << "编译的时间戳:__TIMESTAMP__=" << __TIMESTAMP__ << endl;
    // cout << "当C++编译程序时,标识符__cplusplus就会被定义=" <<  __cplusplus <<endl;

    // #ifdef _WIN32
    //     cout << "这是win系统" <<endl;
    //     typedef long long int64;
    // #else
    //     cout << "这不是win系统"  <<endl;
    //     typedef long int64;
    // #endif
    // int64 a =10;
    // cout <<"a=" << a <<endl;

    cgirl g;
    cboy b;
    g.m_name="西施";
    b.m_name= "子都";
    
    g.m_boy=&b;
    b.m_girl=&g;

    cout << "g.m_boy->m_name=" << g.m_boy->m_name <<endl;
    cout << "b.m_girl->m_name=" << b.m_girl->m_name <<endl;
}
#include "tools.h"
#include "girls.h"

int main()      //文件的编译链接,全局变量的存放和使用
                //extern可以将ab声明成全局变量
{
    cout << "max(5,8)=" << max(5,8) <<endl;
    cout << "min(5,8)=" << min(5,8) <<endl;

    print(3,"你是一只傻傻鸟");

    cout << "aa=" << aa <<endl;
    cout << "bb=" << bb <<endl;
}

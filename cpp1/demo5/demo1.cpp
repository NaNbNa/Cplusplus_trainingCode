#include <iostream>
using namespace std;

int main()
{
    try
    {
        int ii = 0;
        cout << "你是一只什么鸟(1-傻傻的,2--小小鸟):";
        cin >> ii;

        if(ii==1) throw "不好,有人说你是一只傻傻鸟.";
        if(ii==2) throw ii;
        if(ii==3) throw string("不好,有人说你是一只傻傻鸟.");
        
        cout << "你不是一只傻傻鸟,但也是小小的" <<endl;
    }
    catch(int ii)
    {
        cout << "异常的类型是int=" << ii <<endl;
    }
    catch(const char* ii)
    {
        cout << "异常的类型是const char*=" << ii <<endl;
    }
    catch(string ii)
    {
        cout << "异常的类型是string=" << ii <<endl;
    }
    // catch(...)
    // {
    //     cout << "捕获到异常,但未知是什么异常." << endl;
    // }

    cout << "程序继续运行..." <<endl;
}
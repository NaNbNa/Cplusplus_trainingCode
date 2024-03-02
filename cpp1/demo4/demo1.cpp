#include <iostream>
#include <fstream>          // ofstream类需要包含的头文件。
#include <unistd.h>
using  namespace std;       //文件操作的缓冲区和流状态

int main()
{
//   ofstream fout("bbb.txt");   // 打开文件。
//   fout << unitbuf;

//   for (int ii = 0; ii < 1000; ii++)  // 循环1000次。
//   {
//     fout << "ii=" << ii << "，我是一只傻傻傻傻傻傻傻傻傻傻傻傻傻傻的鸟。\n";
//     //fout.flush();      // 刷新缓冲区。
//     usleep(100000);    // 睡眠十分之一秒。
//   }

//   fout.close();  // 关闭文件。

    ifstream fin("test.txt");

    if(fin.is_open()==false)
    {
        cout << "打开文件" << "失败" <<endl;
        return 0;
    }

    string buffer;
    // while(fin >> buffer)
    // {
    //     cout << buffer <<endl;
    // }
    while(true)
    {
        fin >> buffer;
        cout << "eof=" << fin.eof() << ", good()=" << fin.good()
            << ", bad()= " << fin.bad() << ", fail()=" << fin.fail() <<endl;
        if(fin.eof()==true) break;
        cout << buffer <<endl;
    }
    
    fin.close();
    cout << "操作文件结束" <<endl;
}
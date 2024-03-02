#include <iostream>

using namespace std;

int main()          //字符型,ASCLL码重点--
                    //0对应空字符(NULL),10对应换行键,13对应回车键,9对应下一个tab位置
                    //转义字符,0转义为 /0, 10 转义为 /n, 13 转义为 /r
                    //9转义为 /t
                    //原始字面量R"()""
{
    //char a ='X' ;
    //char a = 88;
    // int a = 'X' + 3;
    // cout << "a = " << a << ", sizeof(a) = "
    //      << sizeof(a) <<endl;
    // if ('3' > 51) cout << "ok1" <<endl;
    // else if ('3' == 51) cout << "ok2" <<endl;
    // else if ('3' < 51) cout << "ok3" <<endl;

    // char a = '\\';
    // cout << "\\a = " << a <<endl;
    // //水平制表符--作用是对齐
    // cout << "1\t西施" <<endl;
    // cout << "100\t西\"瓜" <<endl;
    // cout << "10000\t冰'冰" <<endl;
    // cout << "10000\t冰\'冰" <<endl;

    //原始字面量
    string path = "D:\\Edgbrower\\DirectXrepair\\Data\\A";
    string path1 = R"(D:\Edgbrower\DirectXrepair\Data\A)";
    //abcd可以是任意内容,增加理解
    string path2 = R"abcd(D:\Edgbrower\DirectXrepair\Data\A)abcd"; 
    cout << "path = " << path  <<endl;
    cout << "path1 = " << path1 <<endl;
    cout  << "path2 = " << path2 <<endl;
    // backslash连接多行字符串,原始字面量同理
    string str = "<head><meta name=viewport\
                     content=width=device-width\
                     /><meta charSet=utf-8/><title>";
    string str1 = R"(
                     <head><meta name=viewport
                     content=width=device-width
                     /><meta charSet=utf-8/><title>)" ;
    cout << "str = " << str <<endl;
    cout << "str1 = " << str1 <<endl;
  }
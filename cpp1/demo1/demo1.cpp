#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "string::npos=" << string::npos <<endl;

    //默认构造函数
    string s1;      //默认构造函数
    cout << "s1=" << s1 <<endl;     //字符内容
    cout << "s1.capacity()=" << s1.capacity() <<endl;   //容器大小
    cout << "s1.size()=" << s1.size() <<endl;   //存放的字符个数
    cout << "容器动态数组的首地址:" << (void*)s1.c_str() <<endl;    //容器动态数组的首地址

    //cout << "**************" <<endl;
    s1 = "xxxxxxxxxxxxxxxxxxxxxxxxxxx";
    cout << "s1.capacity()=" << s1.capacity() <<endl;
    cout << "s1.size()=" << s1.size() <<endl;
    cout << "容器动态数组的首地址:" << (void*)s1.c_str() <<endl;

    //构造函数:string(const char* s)    //转换函数
    cout << "----------------" <<endl;
    string s2("hello,world");
    cout << "s2=" << s2 <<endl;
    string s3="hello,world";
    cout << "s3=" << s3 <<endl;

    //构造函数string(const string& str):拷贝构造函数,深拷贝
    cout << "----------------" <<endl;
    string s4(s3);
    cout << "s4=" << s4 <<endl;
    string s5=s3;
    cout << "s5=" << s3 <<endl;

    //构造函数4:string(const char* s,size_t n)
    cout << "----------------" <<endl;
    string s6 ("hello,world",5);
    cout << "s6=" <<s6 <<endl;
    cout << "s6.capacity()=" << s6.capacity() <<endl;
    cout << "s6.size()=" << s6.size() <<endl;
    string s7("hello,world",50);
    cout << "s7=" << s7 <<endl;
    cout << "s7.capacity()=" << s7.capacity() <<endl;
    cout << "s7.size()=" << s7.size() <<endl;

    //构造函数5:string(const string& str,size_t pos=0;size_t n =npos)
    cout << "----------------" <<endl;
    string s8(s3,3,5);
    //string s8(s3,3,50);  //same with string s8(s3,3,5);
    cout << "s8=" << s8 <<endl;
    string s9(s3,3);
    cout << "s9=" << s9 <<endl;
    cout << "s9.capacity()=" << s9.capacity() <<endl;
    cout << "s9.size()=" << s9.size() <<endl;
    string s10("hello,world",3);    //使用的构造函数4
    string s11("hello,world",3,5);  //使用的构造函数5
    cout << "s10=" << s10 <<endl;
    cout << "s11=" << s11 <<endl;

    //构造函数6:string()

    //构造函数7:string(size_t n,char c)
    cout << "----------------" <<endl;
    string s12(8,'x');
    cout << "s12=" << s12 <<endl;
    cout << "s12.capacity()=" << s12.capacity() <<endl;
    cout << "s12.size()=" << s12.size() <<endl;
    string s13(30,0);
    cout << "s13=" << s13 <<endl;
    cout << "s13.capacity()=" << s13.capacity() <<endl;
    cout << "s13.size()=" << s13.size() <<endl;
}
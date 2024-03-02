#include <iostream>
#include <string.h>
using namespace std;       //string作为buffer的用法
                        //真正理解string等类型的本质是空间

int main()
{
    struct st_girl
    {
        int bh;
        char name[30];
        bool yz;
        double weight;
        string memo;        //结构体不建议用类做成员,而且memset会出bug,内存泄露
    }girl;              //大小是:4+32(char+bool)+8+?(15) = 59,错误,30 +30 + 30

    cout << "超女结构体的大小sizeof(st_girl):" << sizeof(st_girl) <<endl;

    string buffer;

    for(int ii=0;ii<10;ii++)
    {
        memset(&girl,0,sizeof(st_girl));
        girl.bh = ii;
        sprintf(girl.name,"西施%02d",ii);
        girl.yz = true;
        girl.weight = 48.5 +ii;
        girl.memo = "中国历史第一美少女";

        buffer.append((char*)&girl,sizeof(st_girl));    //与第四个string的构造函数参数一样
    }

    cout << "buffer.capacity()=\t" << buffer.capacity() <<endl;
    cout << "buffer.size()=\t" << buffer.size() <<endl;

    for(int ii=0;ii<buffer.size()/sizeof(st_girl);ii++)
    {
        //memset(&girl,0,sizeof(st_girl));        //存在bug,string带指针,会出现内存泄露
        memcpy(&girl,buffer.data()+ii*sizeof(st_girl),sizeof(st_girl));

        cout << "bh=" << girl.bh << ", name=" << girl.name << ", yz="
        << girl.yz << ", weight=" << girl.weight  << ", memo=" << girl.memo <<endl;
    }

}
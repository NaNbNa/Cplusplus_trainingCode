#include <iostream>
#include <string.h>

using namespace std;
char* tochar(char* str,const size_t n,const int binary=2)
{
    if(str==0) return 0;        //参数接受处理

    size_t num =n;
    char* p= str;  
    

    while(true)                 //  $p,str;  num,binary                        
    {                      
        *p = num%binary+'0';     //  处理整数,接收余数,int->char

        num /=binary;       //更新
        p++;
        
        if(num==0) break;   //商为0,结束while
    }                       //p指向字符的下一个(未知值),num=0;
    *p=0; p--;              //接受完成,p--指向最后的字符
    
    char* start =str;        //$start, p; temp;
    char temp=0;
    while(p-start>0)        //反转字符串 
    {
        temp =*start;       //交换
        *start = *p;
        *p=temp;

        start++;p--;        //更新
    }                       //交换结束,p-start =0 或者 p-start = -1

    return str;
}
int main()
{
    int binary = 10,num=0;
    char str[65];
    memset(str,0,sizeof(str));

    cout << "num=" ; cin >> num;
    cout << "binary(2 or 10)="; cin >> binary;

    tochar(str,num,binary);
    cout << binary << "进制下的str: =" << str <<"=" <<endl;
}
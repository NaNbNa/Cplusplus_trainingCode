#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;
int atoi(const char* str)
{
    if(str==0) return -1;       //处理接受参数

    const char* p =str;
    int num =0;

    while(*p)       //$p,str;num
    {
        if(*p>='0'&&*p<='9')        //字符不非法
            num = (*p - '0') +num*10;       //处理字符,转为整数
        else  break;                //字符非法

        p++;                        //更新
    }                               //p指向 空 或者指向 非法字符
    
    if(p - str==0)  return 0;       //第一个字符非法或者为空

    return num;

}

long atol(const char* str)
{
    if(str==0) return -1;       //处理接受参数

    const char* p =str;
    long num =0;

    while(*p)       //$p,str;num
    {
        if(*p>='0'&&*p<='9')        //字符不非法
            num = (*p - '0') +num*10;       //处理字符,转为整数
        else  break;                //字符非法

        p++;                        //更新
    }                               //p指向 空 或者指向 非法字符
    
    if(p - str==0)  return 0;       //第一个字符非法或者为空

    return num;
}

long long atoll(const char* str)
{
    if(str==0) return -1;       //处理接受参数

    const char* p =str;
    long long num =0;

    while(*p)       //$p,str;num
    {
        if(*p>='0'&&*p<='9')        //字符不非法
            num = (*p - '0') +num*10;       //处理字符,转为整数
        else  break;                //字符非法

        p++;                        //更新
    }                               //p指向 空 或者指向 非法字符
    
    if(p - str==0)  return 0;       //第一个字符非法或者为空

    return num;
}

double atof(const char* str)         //有bug,不会处理小数部分,精度总是缺失
{
    if(str==0) return -1;       //处理接受参数

    const char* p =str;
    double num =0;              //整数部分
    

    while(*p)       //$p,str;num
    {
        if(*p>='0'&&*p<='9')        //字符不非法
            num = (*p - '0') +num*10;       //处理字符,转为整数
        else  break;                //字符非法(包含.符号)

        p++;                        //更新
    }                               //p指向 空 或者指向 非法字符
    
    if(p - str==0)  return 0;       //第一个字符非法或者为空

    double decimal =0;   //小数部分
    double i =0.1;      
    if(*p++ == '.')       //$p;decimal,i
    {                       //p指向第一个小数位
        while(*p)
        {
            if(*p>='0'&&*p<='9')        //字符不非法
                decimal = (*p - '0')*i +decimal;  //处理字符,转为小数
            else  break;                //字符非法(包含.符号)

            p++;i=i*i;                        //更新
        }
    }

    return num+decimal;
}
int main()
{
    //cout << setprecision(15) <<endl;

    char str[51];
    memset(str,0,sizeof(str));

    cout << "str=\t" ;cin >> str;

    double num = atof(str);
    cout << "num=\t" << num <<endl;

}
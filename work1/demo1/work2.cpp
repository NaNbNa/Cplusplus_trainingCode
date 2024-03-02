#include <iostream>
#include <string.h>
#include <iomanip>
#include <cmath>
using namespace std;
int atoi_(const char * ch);         // 把C风格字符串转换为int整数。
long atol_(const char* ch);         // 把C风格字符串转换为long整数。
long long atoll_(const char* ch);   // 把C风格字符串转换为long long整数。
double atof_(const char* ch);       // 把C风格字符串转换为double浮点数。 //难点

int main()
{
    cout << setprecision(15) <<endl;
    
    cout << "atoi = " << "\t" << atoi_("1234567") <<endl; 
    cout << "atol = " << "\t" << atol_("12345673434244") <<endl;
    cout << "atoll= " << "\t" << atoll_("12345673432344") <<endl;
    cout << "atof_= " << "\t" << atof_("1231.5637") <<endl;
    cout << "atof = " << "\t" << atof("1231.56632457") <<endl;
    // double i =1231.5637;
    // cout << i <<endl;
}

int atoi_(const char * ch)      //int
{
    int value = 0;

    while(*ch!=0)
    {
        if((*ch-'0' >=0) && (*ch -'9'<=0))
        {
            value = (*ch - '0') + value*10;
            ch ++;
        }
        else{
            break;
        }
    }
    
    return value;
}

long atol_(const char * ch)   //long
{
   long value = 0;

    while(*ch!=0)
    {
        if((*ch-'0' >=0) && (*ch -'9'<=0))
        {
             value = (*ch - '0') + value*10;
            ch ++;
        }
        else{
            break;
        }
    }
    
    return value;
}

long long atoll_(const char * ch)  //long long
{
   long long value = 0;

    while(*ch!=0)
    {
        if((*ch-'0' >=0) && (*ch -'9'<=0))
        {
             value = (*ch - '0') + value*10;
            ch ++;
        }
        else{
            break;
        }
    }
    
    return value;
}

double atof_(const char * ch)  //double
{
    double value = 0;        //暂时存储整数,最终存储小数部分
    double valueplus =0;    //存储整数部分
    double result =0;       //存储答案

    int i=0;

    while(*ch!=0)
    {
        if(*ch=='.')
        {
            valueplus = value;  //整数部分需要

            value =i =0;
            ch++;
            continue;
        }
    
        if((*ch-'0' >=0) && (*ch -'9'<=0))
        {
            value = (*ch - '0') + value*10;
            i++; //作用仅是记录小数位数
            ch ++;
        }
        else{
            break;
        }
    }
    
    //加上小数部分
    // result += valueplus;
    // while(value>0)
    // {
    //     result += (value%10)*pow(1.0/10,i);   //double的除法
    //     i--;
    //     value /=10;
    // }
    //cout << "1=" << value*pow(1.0/10,i) <<endl;
    //cout << "2=" << valueplus + value*pow(1.0/10,i) <<endl;

    return valueplus + value*pow(1.0/10,i);
}
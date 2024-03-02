#include <iostream>
#include <string.h>

using namespace std;

void second(char *ch,int num) //二进制
{
    *ch = num%2 + '0';            //-------------
    if (num/2==0) return;

    return second(++ch,num/2);
}

void ten(char *ch,int num)  //十进制
{
    *ch = num%10 + '0';
    if (num/10==0) return;
    return ten(++ch,num/10);         //-------------
}


int main()
{
    char ch[20];
      //-----------------------
    memset(ch,0,sizeof(ch));

    int num=0;
    cout << "输入一个数字(不超过20位):"; cin >> num;

    //ten(ch,num);     //修改ch--十进制
    second(ch,num);  //修改ch--二进制

    //逆转字符串
    int len = strlen(ch);
    int times = len/2;
    char temp =0;
    
    char* lp =ch, *hp = ch + len-1;
    while(times>0)
    {
        temp = *lp;
        *lp =*hp;         
        *hp = temp;         //---------------
        lp++;hp--;times--;  //-----------------
    }
    lp=nullptr;hp=nullptr;

    //cout << "num =" << num << ",转换成十进制是:" << ch <<endl; 
    cout << "num =" << num << ",转换成二进制是:" << ch <<endl;

}
#include <iostream>
#include <string.h>

using namespace std;       //指针的增减操作需要保障,避免越界

int main()
{
    char str[51];
    memset(str,0,sizeof(str));

    cout <<"str="; cin >> str;

    char *start =str, *end = str;  ///$len,start, end
    
    int len =0;
    while(*end)             //end指向0,所以 end-- 指向末尾
    {
        end++;len++;
    }    
    if(len==0)          
        return 0;           //str为空,提前退出,保障end--不出问题
    end--;

    char temp=0;            //$end,start,temp
                            //end和start开始交换.
    while(end -start>0)    //end -start 保证end在start前面
    {
        temp=*start;
        *start = *end;
        *end = temp;
        start++;end--;
    }    
                            //交换结束,处理指针
    start =nullptr;end=nullptr;

    cout << "after:str=" << str << "=" <<endl;

}
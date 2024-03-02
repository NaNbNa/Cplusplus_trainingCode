#include <iostream>
#include <string.h>

using namespace std;        //区分空地址和空字符串,之前的全部作业都没有判断地址是否为空
                            //const常量指针也可以接受空地址,注意判断

void deleterchr(char* str, const int cc= ' ')
{
    if(str==0) return;

    char* pos =0;
    while(*str!=0)
    {
        if(*str==cc&&pos==0) pos =str;
        if(*str!=cc) pos =0;
        str++;
    }
    if(pos) *pos=0;
    return;
}
int main()
{
    char str[51];
    memset (str,0,sizeof(str));

    strcpy(str,"abcdee aaaa aa");
    cout << "删除前:" << str <<endl;
    deleterchr(str,'a');
    cout << "删除后:" << str << "!" <<endl;

    // char* ptr=0, *p =0;
    // ptr = p;
    // if(!(*ptr))
    //     cout << "null" <<endl;
}
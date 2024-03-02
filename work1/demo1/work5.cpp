#include <iostream>
#include <string.h>

using namespace std;        //主要错在空指针和? :的联合使用,
                            // i!=-1?s + i:0(i可能是-1),导致段错误
                            //在使用nullptr时,请尽量在if中使用
                            //nullptr比如在cout中使用会导致后续程序无法运行

const char* mystrchr(const char*s,const int c)
{
    char *s1 = (char*) s;
    char* p1 =0;
    while(*s1) 
    {
        if(*s1==c){
            p1=s1;
            break;
        } 
        s1++;
    }

    return p1;      
}

const char* mystrrchr(const char* s, const int c)
{

    char* s1 = (char*)s;
    char* p1=0;
    while(*s1)
    {
        if(*s1==c) p1 =s1;
        s1++;
    }

    return p1;
}
int main()
{
    char s[101];

    memset(s,0,sizeof(s));

    strcpy(s, "abcdefghijklmnopqrstuvwxyz!abcdefghijklmnopqrstuvwxyz!");

    int len = strlen(s);
    char chr = 'c';

    //cout << strlen(0) <<endl; //fasle,不可行的

    if(mystrchr(s,chr))
        cout << "chr= " << chr << ", 在s中第一个位置是:" << len+1-strlen(mystrchr(s,chr)) <<endl;
    else 
        cout << "chr= " << chr << ", 在s中不存在chr" <<endl;

    //cout << mystrrchr(s,chr) <<endl; //若是执行这条语句,则剩下的代码将不会运行,cout特性

    if(mystrrchr(s,chr))
        cout << "chr= " << chr << ", 在s中最后一个位置是:" << len+1-strlen(mystrrchr(s,chr)) <<endl;
    else
        cout << "chr= " << chr << ", 在s中不存在chr" <<endl;

}

#include <iostream>
#include <string.h>

using namespace std;
int* nextbuild(const char* str)  //kmp算法中的substr的最长公共前后缀数组
{
    char* ptr = (char*) str;

    int plen = strlen(ptr) , *next = new int[plen];

    memset(next, 0, sizeof(int)*plen);      //初始化
    int len =0, pos =1;

    while(pos < plen)
    {
        if(ptr[len]==ptr[pos])
        {
            next[pos] = ++len;
            pos++;
        }
        else 
        {
            if(len==0)
            {
                next[pos] = 0;
                pos++;
            }
            else
            {
                len = next[len-1];
            }
        }
    }
    return next;

}
char* kmpstrstr(const char* str, const char* substr)          //kmp算法
{
    //if(substr==0|| str==0) return 0;
    
    int* next = nextbuild(substr);
    
    int dest =0,  sub =0, len = strlen(substr);
    int pos = 0;
    
    while(str[dest]&&substr[sub])
    {
        if(str[dest] == substr[sub])
        {
            dest++;sub++;
        }
        else
        {
            if(sub==0) dest++;
            else sub = next[sub-1];
        }
    }

    delete[] next;
    
    pos = (sub ==len ? dest - sub : -1);
    char* ptr =0;
    if(pos!=-1) ptr = (char*) str +pos;
    return  ptr;

}

void deletestr(char* str, const char* substr)   
{
    if(str==0||substr==0) return;

    int slen =strlen(substr);

    char* exist=kmpstrstr(str,substr);
    char *p =0;
    while(exist)
    {
        p =exist+slen;
        while(*p)
        {
            *exist = *p;
            exist++;p++;
        }
        if(*exist) *exist =0;

        exist=kmpstrstr(str,substr);
        p=0;
    }
}

void deletestr1(char* str, const char* substr)      //递归
{
    if(str==0||substr==0) return;
    
    char* p =strstr(str,substr);
    if(p==0) return;

    size_t slen = strlen(substr);
    if(slen==0) return;
    size_t len =strlen(str);

    memmove(p,p+slen,len-(p-str)-slen +1);
    deletestr1(str,substr); 
}
void deletestr2(char* str, const char* substr)      //循环
{
    if(str==0||substr==0) return;

    while(true){
        char* p =strstr(str,substr);
        if(p==0) return;

        size_t slen = strlen(substr);
        if(slen==0) return;
        size_t len =strlen(str);

        memmove(p,p+slen,len-(p-str)-slen +1);
    }
}
int main()
{
    char str[51];
    memset(str,0,sizeof(str));

    strcpy(str,"xyzaaxyxxyzyzzaaa");

    cout <<"删除前: " << "="<< str << "=" <<endl;

    //deletestr1(str,"xyz");
    //deletestr2(str,"xyz");
    deletestr(str,"xyz");
    cout <<"删除后: " << "="<< str << "=" <<endl;

}
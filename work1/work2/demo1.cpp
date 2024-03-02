#include <iostream>
#include <string.h>

using namespace std;

char* bfstrstr(const char* str,const char* substr)
{
    if(str==0||substr==0) return 0;

    const char* ps =str;
    const char* psub = substr;
    

    while(*ps&&*psub)       //$ps,str, psub,substr
    {
        if(*ps==*psub)  
        {
            ps++;psub++;    //update
        }
        else
        {
            str++;ps=str;    //reset
            psub = substr;
        }
    }                       //ps->0 || psub->0

    char* p = 0;      //result
    if(*psub==0) p = (char*)(ps - strlen(substr));  //str exist substr

    return p;
}

int* nextbuild(const char* str)
{
    if(str==0) return 0;    //deal param

    const char* p= str;

    size_t slen = strlen(str);
    if(slen==0) return 0;   //deal param

    int* next = new int[slen];
    memset(next,0,sizeof(int)*slen);

    next[0] =0;

    int len =0, pos =1;
    while(pos <slen)        //&p,str,next;  len,pos
    {
        if(p[pos]==p[len])
        {
            len++;          //update

            next[pos] =len;     //
            pos++;          //update
        }
        else
        {
            if(len==0)
            {
                next[pos] =0;   //reset 0
                pos++;          //update
            }
            else
            {
                len = next[len-1];  //df
            }
        }
    }                //pos ==slen

    return next;
}

char* kmpstrstr(const char* str,const char* substr)
{
    if(str==0||substr==0) return 0;     //deal param

    size_t slen = strlen(substr);
    if(slen==0) return 0;               //deal param

    const char* ps = str;
    const char* psub =substr;
    
    int * next= nextbuild(substr);
    
    int i=0,j=0;    //ps--i;    psub--j
    while(ps[i]&&psub[j])      //$ps,psub,next; i,j
    {
        if(ps[i]==psub[j]) 
        {
            i++;j++;        //update i,j
        }
        else
        {
            if(j!=0)        //j-1 safe
            {
                j = next[j-1];  //reset j
            }
            else
            {
                i++;        //update i
            }
        }
    }               //j==slen || ps[i] == 0
    delete[] next;

    char* result =0;
    if(j==slen) result = (char*)(str+(i-j));  //str exist substr

    return result;
}
int main()
{
    char str[101];
    char substr[101];

    memset(str, 0, sizeof(str));
    memset(substr, 0, sizeof(substr));

    strcpy(str,"abcdefghijklmnopqrstuvwxyz!abcdefghijklmnopqrstuvwxyz!");
    strcpy(substr,"!a");

    const char *p =bfstrstr(str,substr);
    //const char *p =kmpstrstr(str,substr);

    if(p) 
    {
        cout << "str:\t=" << str << "=" << endl << "substr:\t=" << substr << "=" <<endl; 
        cout << "首地址开始的字符串为:\t=" << p << "=" <<endl;
    }
    else 
    {
        cout << "str:\t=" << str << "=" << endl << "substr:\t=" << substr << "=" <<endl; 
        cout <<  "str中不存在substr!" <<endl;
    }
}
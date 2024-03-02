#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    bool jx = true;
    char str[31];
    memset(str,0,sizeof(str));

    int len =0;
    while(jx)
    {
        cout << "请输入字符串(长度最多30):" ; cin >> str;
        len = strlen(str);

        cout << "正序显示:";


        for(char* ptr =str;*ptr;ptr++)
            cout << *ptr << " " ;
        cout <<endl;

        cout << "逆序显示:";
        for(char* ptr = str +len-1;*ptr;ptr--)
            cout << *ptr << " " ;
        cout <<endl;

        cout << "是否继续(1-继续,0-停止):"; cin >> jx;
    }
}
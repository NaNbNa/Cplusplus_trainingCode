#include <iostream>
#include <string.h>

using namespace std;                //bug:计算汉字字数时不能使用3个1/3相加,浮点数相加会确实精度
                                    //使用判断语句来统计个数.此外,在这次,忽视了count重置为0
                                    //建议是:写代码途中要牢记所有变量的去向,开始,过程和结果

int sumwords(const char* str)       //默认汉字为3字节时使用
{
    if(str==0) return -1;

    int sum=0;
    int count =0; //一个汉字假设3字节,则达到3时sum+1
    while(*str)
    {
        if(*str<=127 && *str >=0)
            sum ++;
        else 
        {
            count ++;
            if(count==3)
            {
                count =0;
                sum++;
            }
            
        }
        str ++;
    }
    return sum;
}

int sumwords1(const char* str)      //默认汉字为2字节时使用
{
	if (str == 0) return -1;		// 如果传进来的是空地址，直接返回，防止程序崩溃。

	char* p = (char*)str;			// 指向字符串的首地址，用于遍历。
	int     total = 0;					// 统计的结果。
	bool  biswide = false;		// 临时的标志位，标记是否已经有半个汉字了。

	while (*p)	// 遍历字符串。
	{
		if ((unsigned char) *p < 128) {		// 如果是ASCII码标准字符，注意，当前字符一定要转成unsigned char。
			total ++;									   // ASCII码标准字符算一个字。
		}
		else {												// 如果是ASCII码扩展字符，表示它是半个汉字。
			if (biswide == true) {					// 如果已经有半个汉字了。
				total++;							       // 加上当前半个汉字，刚好是一个字。
				biswide = false;					   // 清空半个汉字的标志位。
			}
			else {
				biswide = true;						// 设置已存在半个汉字的标志位。
			}
		}

		p++;
	}

	return total;	// 返回统计结果。
}
int main()
{
    char str[101];
    memset(str,0,sizeof(str));

    strcpy(str, "西A施AA制度,冰冰也是!");  //13
    //strcpy(str, "a西a施西a");  //
    // int len =strlen(str);
    // for(int i=0;i<len;i++)
    //     cout << "str[" << i << "]= " << (int)(unsigned char)str[i] <<endl; 

    //strcpy(str, "aaffaf!");
    if(str)
       { 
        cout << "=" << str << "=" <<endl;
        cout << "长度是:" << sumwords(str) <<endl;
       }
    //cout << sumwords("我是一只a傻傻鸟。") << endl;
}
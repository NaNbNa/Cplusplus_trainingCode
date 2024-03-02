#include <iostream>
#include <string.h>

using namespace std;        //加备注可以让人理顺思维,减少bug,一定要加
                            //memset貌似只能初始化为0,其他值不行

void rrand(int arr[], const int len, const int minvalue=0)
{
    if(arr==0) return;
    
    srand(time(0));

    int i= 0; 
    int temp=0;

    while(i<len)
    {
        temp =rand()%len+minvalue;

        int j=0;
        for(j=0;j<i;j++)
            if(arr[j]==temp)
            {
                break;
            }
           
        if(i==j) 
        {
            arr[i] =temp;
            i++;
        }
    }
}
void dealcards(int arr[][13])  //arr需要初始化全为0才可以使用
{
    if(arr==0) return;

    int cards[4];   //四个人手中牌数
    memset(cards,0,sizeof(cards));     //只能初始化为0

    int has[52];    //已经发的牌数
    int hpos =0; //给has服务
    memset(has,0,sizeof(has)); //0不是牌号,放心使用

    srand(time(0));

    int i=0;
    int temp=0,pos =0; //pos是人的编号
    while(i<52)
    {
        
        temp = rand()%52+1; //随机生成牌号
        
        int j=0;
        for(;j<i;j++)    //不能重复的牌,检查牌          //曾存在bug:i<j,无法跳出下面的if(i!=j) continue;循环
            if(has[j]==temp)
                break;
        
        if(i!=j) continue; //避免进入随机选发到牌的对象


        //随机选择发到牌的对象
        while(true){
            pos = rand()%4;
            if(cards[pos]<13)
            {
                cards[pos]++;
                break;
            }
        }
        for(int put=0;put<13;put++) //发牌
            if(arr[pos][put]==0)
            {
                has[hpos] = temp;
                arr[pos][put] =temp;
                break;
            }

       i++;  //最终
       hpos++;
    }
}

void dealcards1(int arr[][13])
{
    int arr1[52];
    rrand(arr1,52,1);

    int arr2[52];
    rrand(arr2,52);

    int j=0;
    for(int i=0;i<13;i++)
    {
        arr[0][i] = arr1[arr2[j++]];
        arr[1][i] = arr1[arr2[j++]];
        arr[2][i] = arr1[arr2[j++]];
        arr[3][i] = arr1[arr2[j++]];
    }
}
int main()
{
    int arr[4][13];  //未初始化值很乱
    
    memset(arr,0,sizeof(arr));
   
    dealcards(arr);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
            {
                cout <<"arr[" <<i << "][" << j << "]=" << arr[i][j] << "\t" ;
                if((j+1)%5==0) cout <<endl;
            }
        cout <<endl;
        cout <<"----------------------------------------------------------------------------" <<endl;
    }

    //cout <<"ok" <<endl;
    
}
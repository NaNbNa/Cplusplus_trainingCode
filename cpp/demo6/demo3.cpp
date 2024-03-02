#include <iostream>
#include <string.h>
using namespace std;

struct st_girl
    {
        char name[21] ;//= "西施";   //24
        int age ;//= 25;            //8
        double weight ;//= 48.6;    //8
        char sex ;//= 'X';          //8
        bool yz ;//= false;         //在sex的8中
    };

int main()      //结构体数组
{
    st_girl girls[3];
    memset(girls,0,sizeof(girls));

    strcpy((girls+0)->name,"西施"); (girls+0)->age = 19;girls[0].weight = 49.1;girls[0].sex = 'X';
    girls[0].yz = true;
    //girls[1] = {"西瓜", 2, 10.6, 'X', false};
    //*(girls+2) = {"冰冰", 14, 40.0, 'X', true};

    for(int i=0;i <3;i++)
    {
        cout << "姓名:" << girls[i].name <<", 年龄:" << girls[i].age << ", 体重:" <<
        girls[i].weight << ", 性别:" << girls[i].sex << ", 颜值:" << girls[i].yz <<endl;
    }
}
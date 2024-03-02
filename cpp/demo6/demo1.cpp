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

int main()
{
  
    st_girl stgirl;//{0} ;
    bzero(&stgirl, sizeof(stgirl));  
    //直接算是35byte,但不是,关联到结构体内容对齐

    st_girl stgirl1;
    bzero(&stgirl1, sizeof(stgirl1));
    stgirl1 =stgirl;        //cpy操作


    cout << "sizeof(st_girl) = " << sizeof(st_girl) <<endl;
    cout << "性别:" << stgirl.name << ", 年龄:" << stgirl.age << ", 体重:"  <<  stgirl.weight
    << ", 性别:" << stgirl.sex << ", 颜值:" << stgirl.yz <<endl;
}
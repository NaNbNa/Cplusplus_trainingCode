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
    

void func(st_girl* pst)
{
     cout << "性别:" << pst->name << ", 年龄:" << pst->age << ", 体重:"  <<  pst->weight
    << ", 性别:" << pst->sex << ", 颜值:" << pst->yz <<endl;
    strcpy(pst->name,"西瓜");
    pst->age = 18;
}

int main()      //结构体指针
{
    st_girl* stgirl = new st_girl();

    memset(stgirl,0,sizeof(st_girl));

    cout << "性别:" << stgirl->name << ", 年龄:" << stgirl->age << ", 体重:"  <<  stgirl->weight
    << ", 性别:" << stgirl->sex << ", 颜值:" << stgirl->yz <<endl;

    st_girl* pst = stgirl;

    func(pst);
    cout << "性别:" << pst->name << ", 年龄:" << pst->age << ", 体重:"  <<  pst->weight
    << ", 性别:" << pst->sex << ", 颜值:" << pst->yz <<endl;

    delete stgirl;
}
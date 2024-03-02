#include <iostream>

using namespace std;

struct st_pet           //结构体嵌套结构体
{
    char name[21];
    char type[21];
};
struct st_girl
    {
        char name[21] ;//= "西施";   //24
       //int score[3];
        int age ;//= 25;            //8
        double weight ;//= 48.6;    //8
        char sex ;//= 'X';          //8
        bool yz ;//= false;         //在sex的8中
        struct st_pet pet;
    };


int main()
{
    // st_girl girl;

    st_girl girl = {"西施",25, 48.6,'X',false,{"宝宝", "鸭子"}};

    cout << "姓名:" << girl.name << "的宠物是一只" 
    << girl.pet.type << ",它的名字是:" << girl.pet.name << endl;

    // girl.pet = {"小白","狗"};
    // cout << "姓名:" << girl.name << "的宠物是一只" 
    // << girl.pet.type << ",它的名字是:" << girl.pet.name << endl;

    // for(int i=0;i<3;i++)
    // {
    //     girl.score[i] = 100 +i;
    // }
    // for (int i = 0; i<3;i++) cout << "girl.score[" << i << "]= "  << girl.score[i] <<endl;

    
}
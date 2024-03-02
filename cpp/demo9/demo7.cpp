#include <iostream>
#include <string.h>

using namespace std;

class cgirl 
{
public:
    int m_bh;
    char m_name[3];
    static int m_age;

    cgirl(){
        memset(m_name,0,sizeof(m_name));
        m_age = 0;
    }

    ~cgirl(){}

    void showname(){ cout << "name is:" << m_name <<endl;}

    void showname0(){ cout << "name is:" << "西施" <<endl;}

    void showname1(){ 
        if(this==0) 
        {
            cout << "this为空指针!" <<endl;
            return; 
        }
        cout << "name is:" << m_name <<endl;}

    void showage(){
        //m_name = "d";
        //showname();
        cout << "age = " << m_age <<endl;}
};

int cgirl::m_age = 23;
char aaa;
void func(){}
int main()
{
    cgirl g1;
    cout << "g1的内存大小:" << sizeof(g1) <<endl;
    cout << "g1的内存地址:" << (void*)&g1 <<endl;
    cout << "g1.m_bh的内存地址:" << (void*)&g1.m_bh <<endl;
    
    if((void*)&g1==(void*)&g1.m_bh)         //比较地址的方法
        cout << "对象g1的地址与第一个非static成员变量地址相同!" <<endl;

    cout << "g1.m_name的内存地址:" << (void*)&g1.m_name <<endl;
    cout << "g1.m_age的内存地址:" << (void*)&g1.m_age <<endl;
    cout << "aaa的内存地址:" << (void*)&aaa <<endl;
    //cout << &cgirl::showage <<endl;     //fasle, cout 的bug,没有重载函数指针
    printf("cgirl::showname的内存地址:%p\n",&cgirl::showname);
    printf("cgirl::showage的内存地址:%p\n",&cgirl::showage);
    printf("func的内存地址:%p\n",&func);

    cgirl* g =nullptr;
    g->showname0(); //showname0没有使用this指针,不会崩溃
    g->showname1(); //判断了this指针是否为空
    //g->showname(); //程序会崩溃,因为this为空指针,showname使用了this指针
}
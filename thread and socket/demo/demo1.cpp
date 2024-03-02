#include <iostream>
using namespace std;

int main(int argc, char* argv[],char * envp[])
{
    if(argc!= 4)
    {
        cout << "表白神奇程序的使用方法： ./demo 追求着姓名 被追求者姓名 表白内容"  <<endl;
        return -1;
    }
    else{
        for(int ii=1;ii<4;ii++)
            cout << argv[ii] << endl;
    }

    return 0;

    cout << "一共有" << argc  << "个参数"<<endl;

    for(int ii=0;ii<argc;ii++)
    {
        cout << "第" << ii << "个参数是:" << argv[ii] <<endl;
    }

    // for(int ii=0;envp[ii]!=0;ii++)
    //     cout << "第"<< ii <<"个环境变量: " << envp[ii] <<endl;
    
    setenv("AA","aaaa",0);

    cout << "AA=" << getenv("AA") <<endl;
}
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;    //获取系统时间,存储时间,计时器

int main()
{
    // //chrono::time_point<chrono::system_clock> now = chrono::system_clock::now();
    // auto now = chrono::system_clock::now();     //(c++时间)

    // //time_t t_now = chrono::system_clock::to_time_t(now);    //(UTC时间)
    // auto t_now = chrono::system_clock::to_time_t(now);   
    // t_now = t_now + 24*60*60;   //+1天

    // //tm* tm_now = std::localtime(&t_now);    //(北京时间)
    // auto tm_now = std::localtime(&t_now);    

    // std::cout << std::put_time(tm_now,"%Y-%m-%d %H:%M:%S") << std::endl;    //格式化输出
    // std::cout << std::put_time(tm_now,"%Y-%m-%d") << std::endl;
    // std::cout << std::put_time(tm_now,"%H:%M:%S") << std::endl;
    // std::cout << std::put_time(tm_now,"%Y%m%d%H%M%S") << std::endl;

    // stringstream ss;     //存储时间
    // ss << std::put_time(tm_now,"%Y-%m-%d %H:%M:%S");
    // string timestr = ss.str();
    // cout << timestr <<endl;


    //chrono::steady_clock::time_point start = chrono::steady_clock::now();
    auto start = chrono::steady_clock::now();

    cout << "计时开始..." <<endl;
    for(int ii=0;ii<1000000;ii++)
    {
        //cout << ii <<endl;
    }
    cout << "计时完成..." <<endl;

    //chrono::steady_clock::time_point end = chrono::steady_clock::now();
    auto end = chrono::steady_clock::now();

    auto dt = end -start;       //ns
    cout << "耗时:" << dt.count() <<"纳秒(" << (double)dt.count()/(1000*1000*1000) 
        << "秒)" <<endl;
}
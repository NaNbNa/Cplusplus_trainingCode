#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
    // vector<int> vv;
    // try
    // {
    //     /* code */
    //     vv = {1,2,3};
    //     //vv.at(3) = 5;
    //     vv[3] = 5;      //直接跳过,不会有异常
    //     vv[4] = 5;
    //     vv[5] = 5;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // for(auto val:vv)
    //     cout << val << " ";
    // cout <<endl;

    //string str = "123";
    string str = "";
    //string str = "1232431543542654615451";
    try
    {
        int x = stoi(str);
        cout << "x=" << x <<endl;
    }
    catch(invalid_argument& e)
    {
        cout << "invalid argument" <<endl;
    }
    catch(out_of_range& e)
    {
        cout << "out of range" <<endl;
    }
    catch(...)
    {
        cout << "something else..." <<endl;
    }
    
    cout << "程序继续运行..." <<endl;
}
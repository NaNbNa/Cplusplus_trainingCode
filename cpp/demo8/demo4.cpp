#include <iostream>

using namespace std;            //内联函数--无法递归,不支持函数体大的函数进行内联

inline void show(const short bh, const string message);

int main()  
{
    
}

inline void show(const short bh, const string message)
{
    cout << "亲爱的" << bh << "号 : " << message <<endl;
}
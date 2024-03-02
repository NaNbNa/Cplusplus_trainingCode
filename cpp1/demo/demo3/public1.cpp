#include "public1.h"

namespace bb{
    
    int ab =33;
    void func1()
    {
        cout << "BB调用了func()函数" <<endl;   
    }

    void A1::show()
    {
        cout << "BB调用了A1::show()函数" <<endl;
    }
}
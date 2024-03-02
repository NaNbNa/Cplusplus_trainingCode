#include <iostream>
#include <string.h>

using namespace std;

// string func()
// {
//     return "西施";
// }

double func(int a,double b,const char* c,float d, short e,long f)
{
    cout << "func" <<endl;
    return 1;
}
int main()
{
    // int a =3;cout << "a=" << a <<endl;

    // double b =3.3; cout << "b=" << b <<endl;

    // string c = "西施"; cout << "c=" << c <<endl;

    // auto a =3;cout << "a=" << a <<endl;

    // auto b =3.3; cout << "b=" << b <<endl;

    // auto c = "西施"; cout << "c=" << c <<endl;

    // auto d = func();cout << "d=" << d <<endl;

    double (*pf)(int a,double b,const char* c,float d, short e,long f) ;
    pf =func;
    pf(1,2,"ds",4,5,6);

    auto pf1 = func;        //应用场景1
    pf1(1,2,"ds",4,5,6);
 }
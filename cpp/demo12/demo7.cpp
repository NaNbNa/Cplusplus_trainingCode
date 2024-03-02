#include <iostream>
#include <string>
using namespace std;

class AA
{
public:
    AA()
    {

    }

};
int main()
{
    // int i = 3;
    // int* pi = &i;
    // int& ri = i;

    // cout << "typeid(int)=\t" << typeid(int).name() <<endl;
    // cout << "typeid(i)=\t"   << typeid(i).name() <<endl;
    // cout << "typeid(int*)=\t" << typeid(int*).name() <<endl;
    // cout << "typeid(pi)=\t" << typeid(pi).name() <<endl; 
    // cout << "typeid(int&)=\t" << typeid(int&).name() <<endl; 
    // cout << "typeid(ri)=\t" << typeid(ri).name() <<endl; 
 
    AA a;
    AA* pa = &a;
    AA& ra = a;
    cout << "typeid(AA)=\t" << typeid(AA).name() <<endl;
    cout << "typeid(a)=\t"   << typeid(a).name() <<endl;
    cout << "typeid(AA*)=\t" << typeid(AA*).name() <<endl;
    cout << "typeid(pa)=\t" << typeid(pa).name() <<endl; 
    cout << "typeid(AA&)=\t" << typeid(AA&).name() <<endl; 
    cout << "typeid(ra)=\t" << typeid(ra).name() <<endl; 

    if(typeid(AA)==typeid(a)) cout << "ok1" <<endl;
    if(typeid(AA)==typeid(*pa)) cout << "ok2" <<endl;
    if(typeid(AA)==typeid(ra)) cout << "ok3" <<endl;
    if(typeid(AA)==typeid(pa)) cout << "ok4" <<endl;
    if(typeid(AA*)==typeid(pa)) cout << "ok5" <<endl;
}
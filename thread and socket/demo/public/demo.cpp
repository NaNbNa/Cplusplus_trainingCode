#include <iostream>
#include <string.h>
#include <charconv>
using namespace std;
int main()
{
    char name [51];
    
    string str = to_string(11);
    strcpy(name,str.c_str());

    cout << "name=" << name <<endl;
}
#include <iostream>
#include <string.h>

using namespace std;

int main()
{

    // string str = "XYZ";

    // cout << "str[0] = " << (int)str[0] <<endl;
    // cout << "str[1] = " << (int)str[1] <<endl;
    // cout << "str[2] = " << (int)str[2] <<endl;
    // cout << "str[3] = " << (int)str[3] <<endl;

    char name[11]; 

    //strcpy(name,"hello");
    strncpy(name,"hello",3);
    cout << "name = " << name <<endl;

    //memset(name ,0 , sizeof(name));
    for(int i=0; i<sizeof(name)/sizeof(char);i++)
    {
        cout << "name["<< i << "] = " << (int)name[i] <<endl;
    }
   
}
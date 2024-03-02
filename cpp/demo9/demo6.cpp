#include <iostream>
#include <string.h>

using namespace std;

class cgirl 
{
private:
    static int m_age;
public:
    string m_name;

    cgirl(){};
    cgirl(const string& name,int age)
    {
        m_name = name; m_age =age;
    }

    void showname(){ cout << "name is:" << m_name <<endl;}

    static void showage(){
        //m_name = "d";
        //showname();
        cout << "age = " << m_age <<endl;}

};

int cgirl::m_age = 18;

int main()
{
    // cgirl::showage();
    // cout << "cgirl::m_age:" << cgirl::m_age <<endl;
    cgirl g1("girl1", 18),g2("girl2", 19),g3("girl3", 23);

    g1.showname();g1.showage();
    g2.showname();g2.showage();
    g3.showname();g3.showage();
    cgirl::showage();
    //cout << "cgirl::m_age:" << cgirl::m_age <<endl;
}
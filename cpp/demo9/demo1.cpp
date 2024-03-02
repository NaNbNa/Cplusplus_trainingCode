#include <iostream>
#include <string.h>

using namespace std;

class cgirl
{
    public:
        string name="西施";
    
        int age=20;
        void initdata()     //清空  
        {
            name.clear(); age =0;
        }
        void setvalue(const string& name1,const int age1);
        void show()
        {
            cout << "姓名:" << name << "; 年龄:" << age <<endl;
        }
};

void cgirl::setvalue(const string& name1,const int age1)
{
    name = name1;
    age = age1;
}

int main()
{
    cgirl girl;
    girl.setvalue("冰冰", 18);
    girl.show();
}
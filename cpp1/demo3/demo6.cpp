#include <iostream> 
#include <memory>

using namespace std;        //智能指针的技巧
class AA
{
public:
    string m_name;
    AA()
    {
        cout  << "调用了构造函数AA():" << m_name <<endl;
    }
    AA(const string& name):m_name(name)
    {
        cout << "调用了构造函数AA(const string& name):" << m_name <<endl;
    }

    ~AA()
    {
        cout << "调用了析构函数~AA():" << m_name <<endl;
    }
};

unique_ptr<AA> func()
{
    unique_ptr<AA> pp(new AA("西施func"));
    return pp;
}

void func1(const AA* a)
{
    cout << "func1:" << a->m_name <<endl;
}

void func2(AA* a)
{
    cout << "func2:" << a->m_name <<endl;
    delete a;
}

void func3(unique_ptr<AA>& a)       //传地址
{
    cout << "func3:" << a->m_name <<endl;
}

void func4(unique_ptr<AA> a)        //传值
{
    cout << "func4:" << a->m_name <<endl;  
}

//unique_ptr<AA> pu1(new AA("西施全局"));

int main()
{
    // unique_ptr<AA> p1;
    // p1 = unique_ptr<AA>(new AA("西施局部"));

    
    // cout << "调用func()之前:" <<endl;
    // p1 = func();
    // cout << "调用func()之后." <<endl;

    // cout << "赋nullptr之前" <<endl;      //p1赋值nullptr
    // if(p1!=nullptr) cout << "p1不是空的" <<endl;
    // p1 = nullptr;
    // cout << "赋nullptr之后" <<endl;
    // if(p1==nullptr) cout << "p1是空的" <<endl;

    //cout << "---------------调用func开始:" <<endl;
    //func1(p1.get());            //四种函数调用指针的情况,release和move用法
    //func1(p1.release());
    //func2(p1.release());
    //func3(p1);
    //func4(move(p1));
    //cout << "---------------调用func结束." <<endl;

    //if(p1==nullptr) cout << "p1是空的" <<endl;
    
    //return 0;       //exit对智能指针的影响
    //exit(0);

    //AA* par1 = new AA[2];       //普通指针
    unique_ptr<AA[]> par1(new AA[2]);   //两个[],注意写法  
    //unique_ptr<AA[]> par1(new AA[2]{string("西施0"),string("西施1")}); //强制转化
    par1[0].m_name = "西施0";par1[1].m_name = "西施1";
    cout << "par1[0].m_name = " << par1[0].m_name <<endl;
    cout << "par1[1].m_name = " << par1[1].m_name <<endl;
    //delete[] par1;

    

}
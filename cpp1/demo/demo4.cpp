#include <iostream>
#include <string>
using namespace std;    //static_cast:其他类型指针->void*->其他类型指针
                        //reinterpret_cast:重新解释,转换随意.指针->基础类型,基础类型->指针
                        //const_cast:丢掉指针的const关键字

void func(void* ptr)
{
    //double* pp=static_cast<double*>(ptr);
    long ii = reinterpret_cast<long>(ptr);    //指针->long
    //int ii = reinterpret_cast<int>(ptr);    //指针->int,8byte->4byte,出现截断错误
    cout << "ii=" << ii<<endl;
}

void func1(int* a)
{
    cout << "const_cast:丢掉指针的const关键字" <<endl;
}
int main()
{
    // int ii =3;
    // long ll =ii;
    // double dd =123;
    // long ll1 =dd;
    // long ll2 = (long) dd;                //C 
    // long ll3 = static_cast<long>(dd);    //C++
    // cout << "ll1=" << ll1 << ",ll2=" << ll2 << ",ll3=" << ll3 <<endl;

    // int ii =10;
    // //double* pd1 = &ii;      //false
    // double* pd1 = (double*)&ii;
    // //double* pd2 = static_cast<double*>(&ii); //false
    // void* pv =&ii;
    // double* pd4 = static_cast<double*>(pv);
    // func(&ii);              //static_cast应用场景

    // int ii =10;
    // //double* pd1=&ii;
    // double* pd1=(double*)&ii;
    // double* pd2=reinterpret_cast<double*>(&ii);     //指针->指针,不通过void*        
    // func(&ii);

    // //int ii =10;
    // long ii=10;
    // func(reinterpret_cast<void*>(ii));      //int->指针

    const int *aa=nullptr;
    //int * bb = aa;
    //int* bb = (int *)aa;
    int* bb = const_cast<int*>(aa);
    //func1(aa);
    func1(const_cast<int*>(aa));
}
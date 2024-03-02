#include <iostream>

using namespace std;

void func(int** pp);

int main()          //二级指针
{
    // int ii = 8; cout <<"ii = " << ii << ", ii的地址是:" << &ii <<endl;
    // int* pii = &ii; cout << "pii = " << pii << ", pii的地址是:" << &pii <<"*, pii = "<< *pii << endl;
    // int** ppii = &pii; cout << "ppii = " << ppii <<", ppii的地址是:" << &ppii << ", *ppii = " << *ppii <<endl;
    // cout << "**ppii = " << **ppii <<endl;

    int* p = 0;
    func(&p);
    cout << "p = " << p << ", *p = " << *p <<endl;

}

void func(int** pp)
{
        *pp = new int(3);
        cout <<"pp = " << pp << ", *pp=" << *pp <<endl;
}
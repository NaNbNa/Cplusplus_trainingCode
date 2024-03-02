#include <iostream>

using namespace std;

int compasc(const void* p1, const void* p2) //升序
{
    // if (*(int*)p1 < *(int*)p2) return -1;
    // else if (*(int*)p1 == *(int*)p2) return 0;
    // else
    // return 1;
    return *(int*)p1 - *(int*)p2 ;
     
}
int compadesc(const void* p1, const void* p2) //降序
{
    // if (*(int*)p1 < *(int*)p2) return -1;
    // else if (*(int*)p1 == *(int*)p2) return 0;
    // else
    // return 1;
    return *(int*)p2 - *(int*)p1 ;
     
}

int main()
{
    int a[] = {41, 5, 17, 83, 1, 31, 0, 11, 343, -1, -55, 100};

    qsort(a, sizeof(a)/sizeof(int), sizeof(int), compadesc);

    for(int i =0;i<sizeof(a)/sizeof(int);i++)
    {
        cout << "a[" << i << "] = " << a[i] <<endl;
    }
}
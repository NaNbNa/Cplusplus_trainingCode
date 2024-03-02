#include <iostream>
#include <string.h>

using namespace std;

#define MAXSIZE 100
typedef int elemtype;

struct Seqlist{
    elemtype data[MAXSIZE];
    size_t length;
};

void clearlist(Seqlist& ll)
{
    //ll.length =0;
    //memset(ll.data,0,sizeof(elemtype)*MAXSIZE);
    memset(&ll,0,sizeof(Seqlist));  //当ll不存在指针时可用,因为指针会被清空,而不是清空指针指向的内容
    return;
}

bool insertList(Seqlist &ll,const size_t pos,const elemtype &ee)
{
    if(ll.length==MAXSIZE) {cout << "full,can't insert!" <<endl; return false;} 

    if((pos <1)||(pos>ll.length+1)) {cout << "thr position is illgal!" <<endl; return false;}

    if(pos<ll.length+1)
        memmove(ll.data+pos,ll.data+pos-1,(ll.length-pos+1)*sizeof(elemtype));
    
    memcpy(&ll.data[pos-1],&ee,sizeof(elemtype));

    ll.length++;

    return true;
}

size_t lengthList(const Seqlist&ll)
{
    return ll.length;
}

bool getElem(const Seqlist ll,const size_t pos,elemtype& ee)
{
    if(pos<1||pos>ll.length) return false;

    ee = ll.data[pos-1];
    return true;
}

bool pushFront(Seqlist &ll, const elemtype& ee)
{
    return insertList(ll,1,ee);
}

bool pushBack(Seqlist &ll,const elemtype& ee)
{
    return insertList(ll,ll.length+1,ee);
}

bool isEmpty(const Seqlist&ll)
{
    if(ll.length==0)    return true;
    return false;
}

size_t findElem(const Seqlist& ll,const elemtype& ee)
{
    for(size_t i=0;i<ll.length;i++)
        if(ll.data[i]==ee) return i+1;

    return 0;
}

bool deleteElem(Seqlist& ll,const size_t pos)  //ee,length
{
    if(pos<1||pos>ll.length) return false;
    
    if(pos<ll.length)
        memmove(ll.data+pos-1,ll.data+pos,sizeof(elemtype)*(ll.length-pos));
    else ll.data[ll.length-1] =0;

    ll.length--;
    return true;
}

bool popFront(Seqlist& ll)
{
    return deleteElem(ll,1);
}

bool popBack(Seqlist& ll)
{
    return deleteElem(ll,ll.length);
}

void printList(const Seqlist&ll)
{
    if(ll.length==0) cout << "the list is Empty!" <<endl;

    for(size_t i=0;i<ll.length;i++)
        cout << ll.data[i] <<" ";
    cout <<endl;
}
int main()
{
    Seqlist ll;
    clearlist(ll);

    elemtype ee=0;

    cout << "insert:" <<endl;
    ee =1;insertList(ll,1,ee);
    ee =2;insertList(ll,2,ee);
    ee =3;insertList(ll,3,ee);
    ee =4;insertList(ll,4,ee);
    ee =5;insertList(ll,5,ee);
    ee =6;insertList(ll,6,ee);
    ee =7;insertList(ll,7,ee);
    ee =8;insertList(ll,8,ee);
    ee =9;insertList(ll,9,ee);
    ee =10;insertList(ll,10,ee);
    printList(ll);

    cout << "pushfront 11, pushback 12:" <<endl;
    ee= 11; pushFront(ll,ee);
    ee= 12; pushBack(ll,ee);
    printList(ll);

    cout << "delete 7th elem:" <<endl;
    deleteElem(ll,7);
    printList(ll);

    cout << "popfront,popback:" <<endl;
    popFront(ll);popBack(ll);
    printList(ll);

    getElem(ll,5,ee);
    cout << "get the 5th elem:\t=" << ee << "=" <<endl;

    ee=8;
    cout << "the 8th elem is:\t=" << findElem(ll,ee) << "=" <<endl;

}
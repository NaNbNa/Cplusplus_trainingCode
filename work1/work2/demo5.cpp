#include <iostream>
#include <string.h>
using namespace std;    //动态顺序表--数组,但是用指针指向数组

#define INITSIZE 5
#define EXTSIZE 3

typedef int elem;

struct sqlist
{
    elem* data;
    unsigned int MAXSIZE;
    size_t length;
};

void clearList(sqlist& ll)
{
    ll.length = 0;
    memset(ll.data,0,sizeof(elem)*ll.MAXSIZE);
}

void initList(sqlist& ll)
{
    ll.MAXSIZE = INITSIZE;
    ll.data = new elem[ll.MAXSIZE];
    clearList(ll);
}

void destroyList(sqlist& ll)
{
    delete[] ll.data;      
    ll.data = nullptr;

    ll.MAXSIZE = 0;
    ll.length=0;
}

bool extList(sqlist& ll)
{
    size_t len = ll.MAXSIZE+EXTSIZE;

    elem* newdata = new elem[len];
    if(newdata==nullptr) return false;
    memset(newdata,0,sizeof(elem)*len);

    memcpy(newdata,ll.data,sizeof(elem)*ll.length);

    delete[] ll.data;
    ll.data = newdata;

    ll.MAXSIZE = len;
    return true;
}

bool insertElem(sqlist& ll, const size_t pos,const elem& ee)
{
    if(ll.length==ll.MAXSIZE) 
    {
        if(extList(ll)==false)
         return false;
    }
    if(pos<1||pos>ll.length+1) return false;

    if(pos<ll.length+1)
        memmove(ll.data+pos,ll.data+pos-1,sizeof(elem)*(ll.length-pos+1));
    ll.data[pos-1] = ee;

    ll.length++;

    return true;
}

size_t lengthList(const sqlist& ll)
{
    return ll.length;
}

bool getElem(const sqlist& ll,const size_t pos, elem& ee)
{
    if(pos<1||pos>ll.length) return false;

    ee= ll.data[pos-1];
    return true;
}

bool pushFront(sqlist& ll,const elem& ee)
{
    return insertElem(ll,1,ee);
}

bool pushBack(sqlist& ll,const elem& ee)
{
    return insertElem(ll,ll.length+1,ee);
}

size_t findElem(const sqlist& ll,const elem& ee)
{
    for(int ii=0;ii<ll.length;ii++)
        if(ee==ll.data[ii]) return ii+1;

    return 0;
}

bool deleteElem(sqlist& ll,const size_t pos)
{
    if(pos<1||pos>ll.length) return false;

    memmove(ll.data+pos-1,ll.data+pos,sizeof(elem)*(ll.length-pos));
    ll.data[ll.length-1] =0;

    ll.length--;
    return true;
}

bool popFront(sqlist& ll)
{
    return deleteElem(ll,1);
}

bool popBack(sqlist& ll)
{
    return deleteElem(ll,ll.length);
}

bool isEmpty(const sqlist& ll)
{
    return ll.length==0;
}

void printList(const sqlist& ll)
{
    for(int ii=0;ii<ll.length;ii++)
        cout << ll.data[ii] << " ";
    cout << endl;
}
int main()
{
    sqlist ll;
    initList(ll);
    cout <<"插入元素(1,2,3,4,5,6,7,8,9,10)" <<endl;
    elem ee;
    ee=1;insertElem(ll,1,ee);
    ee=2;insertElem(ll,2,ee);
    ee=3;insertElem(ll,3,ee);
    ee=4;insertElem(ll,4,ee);
    ee=5;insertElem(ll,5,ee);
    ee=6;insertElem(ll,6,ee);
    ee=7;insertElem(ll,7,ee);
    ee=8;insertElem(ll,8,ee);
    ee=9;insertElem(ll,9,ee);
    ee=10;insertElem(ll,10,ee);
    printList(ll);

    cout << "表头插入11" <<endl;
    ee=11; pushFront(ll,ee);printList(ll);

    cout << "表尾插入12" <<endl;
    ee=12; pushBack(ll,ee);printList(ll);

    cout << "在第7个位置插入13" << endl;
    ee=13; insertElem(ll,7,ee);printList(ll);

    cout << "删除表头元素" <<endl;
    popFront(ll);printList(ll);

    cout << "删除表尾元素" <<endl;
    popBack(ll);printList(ll);

    getElem(ll,5,ee);
    cout << "第5个元素是:" << ee <<endl;

    cout << "删除第5个元素" <<endl;
    deleteElem(ll,5);printList(ll);

    ee =8;
    cout << "元素8的位置:" << findElem(ll,ee) << endl;

    destroyList(ll);
}
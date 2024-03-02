#include <iostream>
#include <string.h>

using namespace std;        //静态顺序表
                            //逻辑的数组下标从1开始
                            //数组的内容一个接一个,不可以有空隙
#define MAXSIZE 100

typedef int elem;

struct sqlist
{
    elem data[MAXSIZE];
    size_t length; 
};

void clearList(sqlist& l)
{
    l.length = 0;
    memset(l.data,0,sizeof(elem)*MAXSIZE);
}

bool insertList(sqlist& l,const size_t pos,const elem& e)
{
    if(l.length==MAXSIZE) return false;
    if(pos<1||pos>l.length+1)  return false;

    elem temp;
    int pos1 =pos-1;
    int ii= l.length-1;

    // for(;ii>=pos1;ii--)
    // {
    //     l.data[ii+1] = l.data[ii];   
    // }
    // l.data[ii+1] = e;

    if(pos<l.length+1)  //往后移动
        memmove(l.data+pos,l.data+pos-1,sizeof(elem)*(l.length-pos+1));
    l.data[pos-1] = e;

    l.length++;

    return true;
}

size_t lengthList(const sqlist& l)
{
    return l.length;
}

bool getElem(const sqlist& l,const size_t pos,elem& e)
{
    if(pos<1||pos>l.length) return false;

    e = l.data[pos-1];
    return true;
}

bool pushFront(sqlist& l, elem& e)
{
    return insertList(l,1,e);
}

bool pushBack(sqlist& l,elem& e)
{
    return insertList(l,l.length+1,e);
}

size_t findElem(const sqlist& l,const elem& e)
{

    for(int ii=0;ii<l.length;ii++)
        if(e==l.data[ii])
            return ii+1;
    // int ii =0;
    // for(auto& val:l.data) //循环到maxsize
    // {
    //     if(val==e)
    //         return ii;
    //     ii++;
    // }

    return 0;
}

bool deleteElem(sqlist& l,const size_t pos)
{
    if(pos<1||pos>l.length) return false;

    
    memmove(l.data+pos-1,l.data+pos,sizeof(elem)*(l.length-pos));
    l.data[l.length-1] =0;
    
    l.length--;

    return true;
}

bool popFront(sqlist& l)
{
    return deleteElem(l,1);
}

bool popBack(sqlist& l)
{
    return deleteElem(l,l.length);
}

bool isEmpty(const sqlist& l)
{
    return l.length==0;
}

void printList(const sqlist& l)
{
    for(int ii=0;ii<l.length;ii++)
        cout << l.data[ii] << " ";
    cout << endl;
}


int main()
{
    sqlist ll;
    clearList(ll);

    cout << "插入元素(1,2,3,4,5,6,7,8,9,10)" << endl;
    insertList(ll,1,1); insertList(ll,2,2);
    insertList(ll,3,3);insertList(ll,4,4);
    insertList(ll,5,5);insertList(ll,6,6);
    insertList(ll,7,7);insertList(ll,8,8);
    insertList(ll,9,9);insertList(ll,10,10);
    
    printList(ll);

    cout << "表头插入元素(11),表尾插入元素(12)" <<endl;
    int ee;
    ee = 11, pushFront(ll,ee);
    ee = 12, pushBack(ll,ee);
    printList(ll);

    cout << "在第五个位置插入13" <<endl;
    ee =13; insertList(ll,5,ee);
    printList(ll);

    cout << "删除表头元素" <<endl;
    popFront(ll);printList(ll);

    cout << "删除表尾元素" <<endl;
    popBack(ll);printList(ll);
    

    getElem(ll,6,ee);
    cout << "第6个元素:" << ee <<endl;

    cout << "删除第6个元素:" <<endl;
    deleteElem(ll,6);printList(ll);

    ee =8;
    cout << "元素8的位置:" << findElem(ll,ee) <<endl;

}
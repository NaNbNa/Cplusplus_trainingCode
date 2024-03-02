#include <iostream>
#include <string.h>
#include "demo6.cpp"    //bug, main重复定义
using namespace std;        //桶排序,用于单链表



//-------------------------------------------------------------------

void mergeList(Lnode* a,Lnode* b,Lnode* c)
{
    Lnode* pa =a->next;
    Lnode* pb =b->next;
    Lnode* pc =c;

    while(pa!=nullptr&&pb!=nullptr)
    {
        if(pa->data<pb->data) 
        {   
            pc->next = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pb = pb->next;
        }
        pc = pc->next;
    }

    if(pa!=nullptr)  pc->next = pa;
    if(pb!=nullptr)  pc->next = pb;
    
    a->next = nullptr;              //重点,保留头节点head,因为没delete
    b->next = nullptr;
}

bool PushOrder(Lnode* head,const ElemType& ee)
{
    if(head==nullptr) return false;

    Lnode* pp = head->next;
    Lnode* tail = head;

    while(pp!=nullptr)
    {
        if(pp->data>=ee) 
        {
            insertPriorNode(pp,ee);
            break;
        }
        tail = pp;
        pp = pp->next;
    }

    if(pp==nullptr) insertNextNode(tail,ee);

    return true;
}


void bucketSort(int arr[], int len,int bucketnum)
{
    Lnode* bucket[bucketnum];
    for(int ii=0;ii<bucketnum;ii++)
        bucket[ii] = initList();
    
    for(int ii=0;ii<len;ii++)
    {
        PushOrder(bucket[ii%bucketnum],arr[ii]);
    }

    cout << "全部桶的元素:" <<endl;
    for(int ii=0;ii<bucketnum;ii++)
    {
        cout << "桶" << ii <<": ";
        printList(bucket[ii]);
    }

    Lnode* result = initList();
    Lnode* ll = initList();
    Lnode* temp;
    for(int ii=0;ii<bucketnum;ii++)
    {
        mergeList(ll,bucket[ii],result);

        temp = ll->next;
        ll->next = result->next;
        result->next = temp;
    }

    cout << "合并后的桶: " ; 
    printList(ll);

    Lnode* pp = ll->next;
    int pos=0;
    while(pp!=nullptr)
    {
        arr[pos++] = pp->data;
        pp = pp->next;
    }

    destroyList(result);
    destroyList(ll);
    for(int ii=0;ii<bucketnum;ii++)
        destroyList(bucket[ii]);
}

int main()
{
    cout << "bucketSort" <<endl;
    int arr[] = {44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
    int len = sizeof(arr)/sizeof(int);

    cout <<"排序前:" <<endl;
    for(int ii=0;ii<len;ii++)
    {
        cout << arr[ii] <<"  ";
    }
    cout <<endl;

    bucketSort(arr,len,3);

    cout <<"排序后:" <<endl;
    for(int ii=0;ii<len;ii++)
    {
        cout << arr[ii] <<"  ";
    }
    cout <<endl;
}
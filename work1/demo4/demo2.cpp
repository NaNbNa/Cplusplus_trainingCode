#include <iostream>
#include <string.h>

using namespace std;

typedef int elemtype;

struct lnode
{
    elemtype data;
    struct lnode* next;
};

struct linkQueue
{
    lnode* head,*tail;
};
bool initQueue(linkQueue &q)
{
    q.head = new (std::nothrow)lnode;
    if(q.head==nullptr) return false;

    q.tail = q.head;

    q.head->next = nullptr;

    return true;
}

void destroyQueue(linkQueue& q)   //指针
{
    lnode* temp;
    while(q.head==nullptr)
    {
        temp= q.head->next;
        delete q.head;
        q.head = temp;
    }
}

bool inQueue(linkQueue& q,const elemtype& ee)
{
    if(q.head==nullptr) return false;

    lnode* temp= new (std::nothrow) lnode;
    if(temp==nullptr) return false;

    temp ->data = ee;
    temp->next = nullptr;

    q.tail->next= temp;
    q.tail = temp;

    return true;
}

bool outQueue(linkQueue& q,elemtype& ee)
{
    if(q.head==nullptr) return false;

    if(q.head->next==0) return false;

    lnode* temp =q.head->next;
    q.head->next = temp->next;

    if(temp==q.tail)  q.tail = q.head;

    ee = temp->data;
    delete temp;

    return true;
}
void printQueue(linkQueue& q)
{
    if(q.head==nullptr) return;

    lnode* pp =q.head->next;

    while(pp!=nullptr)
    {
        cout << pp->data << " ";
        pp = pp->next;
    }
    cout <<endl;
}

size_t queueLength(linkQueue& q)
{
    if(q.head==nullptr) return false;

    lnode* pp =q.head->next;

    size_t len =0;
    while(pp!=nullptr) {len++; pp=pp->next;}

    return len;
}


void clearQueue(linkQueue& q)
{
    if(q.head==nullptr) return;

    lnode* temp =0;
    lnode* temp1= q.head->next;

    while(temp1!=nullptr)
    {
        temp = temp1->next;
        delete temp1;
        temp1 =temp;
    }

    q.head->next =nullptr;
    q.tail = q.head;
    
}

int main()
{
    linkQueue q;
    initQueue(q);
    cout << "inQueue:" <<endl;
    inQueue(q,1);
    inQueue(q,2);
    inQueue(q,3);
    inQueue(q,4);
    inQueue(q,5);
    printQueue(q);

    cout << "the length is: " << queueLength(q) <<endl;

    cout << "outQueue:" <<endl;
    elemtype ee=0;
    outQueue(q,ee);
    printQueue(q);

    cout << "出队元素的值:" << ee <<endl;

    cout << "clearQueue:" <<endl;
    clearQueue(q);
    printQueue(q);

    cout << "----------------------------------------" <<endl;

    cout << "inQueue:" <<endl;
    inQueue(q,11);
    inQueue(q,12);
    inQueue(q,13);
    inQueue(q,14);
    inQueue(q,15);
    printQueue(q);

    cout << "the length is: " << queueLength(q) <<endl;

    cout << "outQueue:" <<endl;
    outQueue(q,ee);
    printQueue(q);
    cout << "出队元素的值:" << ee <<endl;

    destroyQueue(q);
}
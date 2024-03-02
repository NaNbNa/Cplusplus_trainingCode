#include <iostream>
#include <string.h>

using namespace std;    //双链表

typedef int ElemType;

struct Lnode
{
    ElemType data;
    Lnode* next;
    Lnode* prior;
};

Lnode* initList()
{
    Lnode* head = new(std::nothrow) Lnode;
    if(head==nullptr) return nullptr;

    head->next = nullptr;
    head->prior = nullptr;
    return head;
}

void destroyList(Lnode* head)
{
    Lnode* temp;
    while(head!=nullptr)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
}

bool pushFront(Lnode* head,const ElemType& ee)
{
    if(head==nullptr) return false;

    Lnode* temp = new(std::nothrow) Lnode;
    if(temp==nullptr) return false;
    temp->data = ee;

    temp->prior = head;
    temp->next = head->next;

    if(head->next!=nullptr)
        head->next->prior = temp;
    head->next = temp;

    return true;
}

void printList(const Lnode* head)
{
    if(head==nullptr) return;

    Lnode* ptr = head->next;
    while(ptr!=nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

bool pushBack(Lnode* head,const ElemType& ee)
{
    if(head==nullptr) return false;

    Lnode* pp = head;
    while(pp->next!=nullptr)
        pp = pp->next;

    Lnode*  temp = new(std::nothrow) Lnode;
    if(temp==nullptr) return false;
    temp->data =ee;

    temp->prior = pp;
    temp->next = nullptr;
    pp->next = temp;

    return true;
}

size_t listLength(const Lnode* head)
{
    if(head==nullptr) return 0;

    Lnode* pp = head->next;
    size_t len = 0;

    while(pp!=nullptr)
    {
        len++;pp = pp->next;
    }

    return len;
}

bool popFront(Lnode* head)
{
    if(head==nullptr||head->next==nullptr) return false;

    Lnode* temp = head->next->next;
    delete head->next;
    head->next = temp;
    if(head->next!=nullptr) 
        head->next->prior = head;

    return true;
}

bool popBack(Lnode* head)
{
    if(head==nullptr||head->next==nullptr) return false;

    Lnode* pp =head;
    while(pp->next->next!=nullptr) pp = pp->next;

    delete pp->next;
    pp->next = nullptr;

    return true;
}

void clearList(Lnode* head)
{
    if(head==nullptr) return;

    Lnode* temp;
    Lnode* pp = head->next;
    while(pp!=nullptr)
    {
        temp = pp->next;
        delete pp;
        pp = temp;
    }

    head->next = nullptr;
}

Lnode* locateElem(const Lnode* head,const ElemType& ee)
{
    if(head==nullptr) return nullptr;

    Lnode* pp = head->next;
    while(pp!=nullptr)
    {
        if(pp->data==ee) break;
        pp = pp->next;
    }

    return pp;
}
Lnode* locateNode(const Lnode* head,const size_t n)
{
    if(head==nullptr) return nullptr;

    Lnode* pp = head->next;
    size_t pos = n-1;

    while(pp!=nullptr&&pos>0)
    {
        pos--;pp = pp->next;
    }

    if(pp==nullptr) return nullptr;
    return pp;
}

bool insertNextNode(Lnode* pp,const ElemType& ee)
{
    if(pp==nullptr) return false;

    Lnode* temp = new(std::nothrow) Lnode;
    if(temp==nullptr) return false;
    temp->data = ee;
    
    temp->prior = pp;
    temp->next = pp->next;
    if(pp->next!=nullptr) 
        pp->next->prior = temp;
    pp->next =temp;

    return true;
}

bool insertPriorNode(Lnode* pp,const ElemType& ee)
{
    if(pp==nullptr) return false;
    
    Lnode* tmp = new(std::nothrow) Lnode;
    if(tmp==nullptr) return false;

    tmp->data = pp->data;
    pp->data = ee;

    tmp->prior = pp;
    tmp->next = pp->next;
    if(pp->next!=nullptr) 
        pp->next->prior = tmp;
    pp->next = tmp;

    return true;
}

bool deleteNode(Lnode* pp)      //可以删除最后节点
{
    if(pp==nullptr) return false;

    if(pp->next!=nullptr)
        pp->next->prior = pp->prior;
    pp->prior->next = pp->next;
    delete pp;
    
    return true;
}

int main()
{
    Lnode* ll = initList();

    cout <<"头插法向链表插入3,2,1" <<endl;
    ElemType ee;
    ee = 3;pushFront(ll,ee);
    ee = 2;pushFront(ll,ee);
    ee = 1;pushFront(ll,ee);
    printList(ll);
    cout << "尾插法插入4,5,6" <<endl;
    ee = 4;pushBack(ll,ee);
    ee = 5;pushBack(ll,ee);
    ee = 6;pushBack(ll,ee);
    printList(ll);
    cout << "表长=" << listLength(ll) <<endl;

    cout << "删除头节点" <<endl;
    popFront(ll);printList(ll);

    cout << "删除尾节点" <<endl;
    popBack(ll);printList(ll);

    ee=4;Lnode* p1 =locateElem(ll,ee);
    cout << "元素为4的节点的地址是: " << p1 << ", 值=" <<p1->data <<endl;

    Lnode* p2 = locateNode(ll,3);
    cout << "位序为3的节点的地址是: " << p2 << ", 值=" <<p2->data <<endl;

    cout << "在" << p2->data << "之后插入元素8:" <<endl;
    ee=8;insertNextNode(p2,ee);
    printList(ll);

    cout << "在" << p2->data << "之前插入元素7:" <<endl;
    ee =7;insertPriorNode(p2,ee);
    printList(ll);

    cout << "清空链表" <<endl;
    clearList(ll);printList(ll);
    cout <<"表长=" << listLength(ll) <<endl;
    destroyList(ll);
}
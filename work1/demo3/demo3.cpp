#include <iostream>
#include <string.h>

using namespace std;

typedef int elemtype;

struct lnode
{
    elemtype data;
    struct lnode* next;
};

lnode* initList()
{
    lnode* head = new (std::nothrow)lnode;

    if(head==nullptr) return nullptr;

    head->next = nullptr;

    return head;
}

void destroyList(lnode* head)   //指针
{
    lnode* temp;
    while(head==nullptr)
    {
        temp= head->next;
        delete head;
        head = temp;
    }
}

bool pushFront(lnode* head,const elemtype& ee)
{
    if(head==nullptr) return false;

    lnode* temp= new (std::nothrow) lnode;
    if(temp==nullptr) return false;

    temp ->data = ee;
    temp->next = head->next;
    head->next= temp;

    return true;
}

bool pushBack(lnode* head,const elemtype& ee)
{
    if(head==nullptr) return false;

    lnode* pp =head;

    while(pp->next!=nullptr) pp=pp->next;

    lnode* temp = new (std::nothrow) lnode;
    if(temp==nullptr) return false;

    temp->data = ee;
    temp->next =nullptr;
    pp->next = temp;

    return true;
}
size_t listLength(lnode* head)
{
    if(head==nullptr) return false;

    lnode* pp =head->next;

    size_t len =0;
    while(pp!=nullptr) {len++; pp=pp->next;}

    return len;
}

bool popfront(lnode *head)
{
    if(head==nullptr) return false;

    if(head->next==nullptr) return false;

    lnode* pp =head->next;
    head->next = pp->next;

    delete pp;
    return true;
} 

bool popBack(lnode* head)
{
    if(head==nullptr) return false;
    if(head->next ==nullptr)  return false;

    lnode* p = head;
    while(p->next->next!=nullptr) p = p->next;

    delete p->next;
    p->next =nullptr;

    return true;
}

void clearList(lnode* head)
{
    if(head==nullptr) return;

    lnode* temp =0;
    lnode* temp1= head->next;

    while(temp1!=nullptr)
    {
        temp = temp1->next;
        delete temp1;
        temp1 =temp;
    }

    head->next =nullptr;
}

lnode* locateElem(const lnode* head,const elemtype& ee)
{
    if(head==nullptr) return 0;

    lnode* p = head->next;

    while(p!=nullptr)
    {
        if(p->data==ee) return p;

        p=p->next;
    }       //p->0
    return p;
}

lnode* locateNode(lnode* head,const size_t n)
{
    if(head==0) return 0;

    lnode* p = head;
    size_t pos = n;

    while(p!=0&&pos>0)
    {
        p=p->next;
        pos--;
    }

    return p;
}

bool insertNextnode(lnode* pp,const elemtype& ee)   //pp之后插入元素
{
    if(pp==nullptr) return false;

    lnode * temp= new lnode;

    temp->data =ee;

    temp->next = pp->next;
    pp->next = temp;

    return true;
}

bool insertPriornode(lnode* pp,const elemtype& ee)   //pp之前插入元素
{
    if(pp==nullptr) return false;

    lnode * temp= new lnode;

    temp->data = pp->data;
    temp->next = pp->next;

    pp->data = ee;
    pp->next = temp;

    return true;
}

bool deleteLnode(lnode* pp)
{
    if(pp==0) return false;

    if(pp->next!=0)
    {
        lnode*temp = pp->next;
        pp->data = temp->data;
        pp->next = temp->next;
        delete temp;
    }
    else
    {
        return false;
    }

    return true;
}
void printList(const lnode* head)
{
    if(head==nullptr) return;

    lnode* pp =0;
    pp = head->next;

    while(pp!=nullptr)
    {
        cout << pp->data << " ";
        pp = pp->next;
    }
    cout <<endl;
}

int main()
{
    lnode* ll = initList();
    cout << "pushfront:" <<endl;
    pushFront(ll,1);
    pushFront(ll,2);
    pushFront(ll,3);
    printList(ll);

    cout << "pushback:" <<endl;
    pushBack(ll,4);
    pushBack(ll,5);
    pushBack(ll,6);
    printList(ll);

    cout << "the length is: " << listLength(ll) <<endl;

    cout << "popfront:" <<endl;
    popfront(ll);  
    printList(ll);

    cout << "popback:" <<endl;
    popBack(ll);
    printList(ll);

    cout << "clearlist:" <<endl;
    clearList(ll);
    printList(ll);

    cout << "----------------------------------------" <<endl;

    cout << "pushfront:" <<endl;
    pushFront(ll,11);
    pushFront(ll,12);
    pushFront(ll,13);
    printList(ll);

    cout << "pushback:" <<endl;
    pushBack(ll,14);
    pushBack(ll,15);
    pushBack(ll,16);
    printList(ll);

    lnode* p1 = locateElem(ll,14);
    cout << "元素为14的的地址:\t"  << p1 << "\tthe value:" << p1->data <<endl;

    lnode* p2 = locateNode(ll,5);
    cout << "位序为5的元素的地址: \t" << p2 << "\tthe value:" << p2->data <<endl;

    cout << "在" << p2->data << "之后插入元素8" <<endl;
    insertNextnode(p2,8);
    printList(ll);

    cout << "在" << p2->data << "之前插入元素7" <<endl;
    insertPriornode(p2,7);
    printList(ll);

    destroyList(ll);
}
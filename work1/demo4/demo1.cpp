#include <iostream>
#include <string.h>

using namespace std;

typedef int elemtype;

struct lnode
{
    elemtype data;
    struct lnode* next;
};

lnode* initStack()
{
    lnode* head = new (std::nothrow)lnode;

    if(head==nullptr) return nullptr;

    head->next = nullptr;

    return head;
}

void destroyStack(lnode* head)   //指针
{
    lnode* temp;
    while(head==nullptr)
    {
        temp= head->next;
        delete head;
        head = temp;
    }
}

bool push(lnode* head,const elemtype& ee)
{
    if(head==nullptr) return false;

    lnode* temp= new (std::nothrow) lnode;
    if(temp==nullptr) return false;

    temp ->data = ee;
    temp->next = head->next;
    head->next= temp;

    return true;
}


size_t StackLength(lnode* head)
{
    if(head==nullptr) return false;

    lnode* pp =head->next;

    size_t len =0;
    while(pp!=nullptr) {len++; pp=pp->next;}

    return len;
}

bool pop(lnode *head,elemtype& ee)
{
    if(head==nullptr) return false;

    if(head->next==nullptr) return false;

    lnode* pp =head->next;
    head->next = pp->next;

    ee = pp->data;
    delete pp;
    return true;
} 


void printStack(const lnode* head)
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
    lnode* ss = initStack();
    cout << "pushfront:" <<endl;
    push(ss,1);
    push(ss,2);
    push(ss,3);
    printStack(ss);

    cout << "the length is: " << StackLength(ss) <<endl;

    cout << "pop:" <<endl;
    elemtype ee =0;
    pop(ss,ee);  
    printStack(ss);

    cout << "出栈的元素的值:" << ee <<endl;

    destroyStack(ss);
}
#include <iostream>
using namespace std;

typedef int ElemType;

struct SNode
{
    ElemType data;
    SNode* next;
};

SNode* initStack()
{
    SNode* newdata = new(std::nothrow) SNode;
    if(newdata==nullptr) return nullptr;

    newdata->next = nullptr;
    return newdata;
}

void destoryStack(SNode* head)
{
    SNode* temp;
    while(head!=nullptr)
    {   
        temp = head->next;
        delete head;
        head = temp;
    }
}

bool Push(SNode* head,const ElemType& ee)
{
    if(head==nullptr) return false;

    SNode* temp = new(std::nothrow) SNode;
    if(temp==nullptr) return false;
    temp->data = ee;

    temp->next =head->next;
    head->next = temp;

    return true;
}
void clearStack(SNode* head)
{
    if(head==nullptr) return;

    SNode* pp =head->next;
    SNode* temp;
    while(pp!=nullptr)
    {
        temp = pp->next;
        delete pp;
        pp = temp;
    }
    head->next = nullptr;
}

void printStack(const SNode* head)
{
    if(head==nullptr) return;

    SNode* pp = head->next;
    while(pp!=nullptr)
    {
        cout << pp->data << " ";
        pp = pp->next;
    }
    cout <<endl;
}
size_t StackLength(const SNode* head)
{
    if(head==nullptr) return 0;

    size_t len = 0;
    
    SNode* pp = head->next;
    while(pp!=nullptr)
    {
        pp = pp->next;
        len++;
    }

    return len;
}

bool Pop(SNode* head,ElemType& ee)
{   
    if(head==nullptr) return false;
    if(head->next==nullptr) return false;

    ee = head->next->data;

    SNode* temp = head->next;
    head->next = head->next->next;
    delete temp;

    return true;
}
int main()
{
    SNode* ss = initStack();

    cout << "入栈6,5,4,3,2,1(6先进,1在末尾)" <<endl;
    ElemType ee;
    ee = 6;Push(ss,ee);
    ee = 5;Push(ss,ee);
    ee = 4;Push(ss,ee);
    ee = 3;Push(ss,ee);
    ee = 2;Push(ss,ee);
    ee = 1;Push(ss,ee);
    printStack(ss);

    cout << "栈长= " << StackLength(ss) <<endl;

    Pop(ss,ee);
    cout << "出栈元素是: " << ee << endl; 
    printStack(ss);

    Pop(ss,ee);
    cout << "出栈元素是: " << ee << endl;
    printStack(ss); 

    Pop(ss,ee);
    cout << "出栈元素是: " << ee << endl; 
    printStack(ss);

    clearStack(ss);
    cout << "清空栈,栈长= " << StackLength(ss) <<endl;

    destoryStack(ss);
}
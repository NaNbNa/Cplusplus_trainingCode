#include <iostream>
#include <string.h>
using namespace std;

typedef int ElemType;   //队列

struct LNode{
    ElemType data;
    LNode* next;
};

struct LinkQueue
{
    LNode* head,*tail;
};

bool initQueue(LinkQueue& qq)
{
    qq.head = new(std::nothrow) LNode;
    if(qq.head==nullptr) return false;

    qq.head->next = nullptr;
    qq.tail = qq.head;

    return true;
}

void destroyQueue(LinkQueue& qq)
{
    LNode* pp = qq.head;
    LNode* temp;
    while(pp!=nullptr)
    {
        temp = pp->next;
        delete pp;
        pp = temp;
    }
}

bool inQueue(LinkQueue& qq, const ElemType& ee)
{  
    if(qq.head==nullptr) return false;

    LNode* temp = new(std::nothrow) LNode;
    if(temp==nullptr) return false;
    temp->data = ee;

    temp->next = nullptr;
    qq.tail->next = temp;
    qq.tail =temp;

    return true;
}

bool outQueue(LinkQueue& qq,ElemType& ee)
{
    if(qq.head==nullptr) return false;  
    if(qq.head->next==nullptr) return false;
    
    ee = qq.head->next->data;
    
    LNode* temp = qq.head->next ;
    qq.head->next = qq.head->next->next;

    if(temp ==qq.tail)  qq.tail = qq.head;
    delete temp;

    return true;
}

void PrintQueue(const LinkQueue& qq)
{
    if(qq.head==nullptr) return;

    LNode* pp = qq.head->next;
    while(pp!=nullptr)
    {
        cout << pp->data << " ";
        pp = pp->next;
    }
    cout <<endl;
}

size_t Length(const LinkQueue& qq)
{
    if(qq.head==nullptr) return 0;

    LNode* pp = qq.head->next;
    size_t len = 0;
    while(pp!=nullptr)
    {
        len++; pp = pp ->next;
    }
    return len;
}
void clearQueue(LinkQueue& qq)
{
    if(qq.head==nullptr) return;

    LNode* pp =qq.head->next;
    LNode* temp;
    while(pp!=nullptr)
    {
        temp = pp->next;
        delete pp;
        pp = temp;
    }
    qq.head->next = nullptr;
    qq.tail = qq.head;
}
int main()
{
    LinkQueue qq;
    memset(&qq,0,sizeof(qq));
    initQueue(qq);

    cout << "元素1,2,3,4,5,6按顺序入队" <<endl;
    ElemType ee;
    ee = 1; inQueue(qq,ee);
    ee = 2; inQueue(qq,ee);
    ee = 3; inQueue(qq,ee);
    ee = 4; inQueue(qq,ee);
    ee = 5; inQueue(qq,ee);
    ee = 6; inQueue(qq,ee);
    

    cout << "队列的长度 = " << Length(qq) <<endl;

    cout << "队列中的元素是: " << endl;
    PrintQueue(qq);

    cout << "出队:" <<endl;
    while(outQueue(qq,ee)==true)
    {
        cout << "出队的元素为" << ee <<endl;
    }

    cout << "元素11,12,13,14,15入队" << endl;
    ee=11;inQueue(qq,ee);
    ee=12;inQueue(qq,ee);
    ee=13;inQueue(qq,ee);
    ee=14;inQueue(qq,ee);
    ee=15;inQueue(qq,ee);
    
    cout << "队列的长度 = " << Length(qq) <<endl;

    cout << "队列中的元素是: " << endl;
    PrintQueue(qq);

    cout << "出队:" <<endl;
    while(outQueue(qq,ee)==true)
    {
        cout << "出队的元素为" << ee <<endl;
    }

    destroyQueue(qq);
 }
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

void quicksort(int arr[], int len)                  //先动右指针,后动左指针
{
    if(arr==0||len<2) return;           //deal param

    int mid = arr[0];
    int l = 0, r =len-1;

    while(l<r)                  //$arr;     l,r,empty
    {
        while(arr[r] >= mid&&l<r) r--;              

        if(l<r)     //arr[r] < mid
        {
            arr[l] =arr[r];
            l++;     //update l
        }

        while(arr[l] <= mid&&l<r) l++;

        if(l<r)     //arr[l] > mid
        {
            arr[r] =arr[l];   
            r--;           //update r
        }
    }   //l==r
    arr[l] = mid;
    
    quicksort(arr,l);
    quicksort(arr+r+1,len-1-r);
}

bool pushOrder(lnode* head,elemtype& ee)
{
    if(head==0) return false;

    lnode *p =head->next;
    lnode* tail = head;
    while(p!=0)     //$p
    {
        if(p->data >= ee)  break;
        
        tail =p;
        p = p->next;
    }   //p= 0 or p->? ; if p==0, then tail = p->prior

    if(p==0) insertNextnode(tail,ee);
    else insertPriornode(p,ee);
    
    return true;
}

void listsort(lnode* head)
{
    if(head==0) return;

    int len = listLength(head);

    if(len<2) return;

    int* arr = new int[len];    //分配
    memset(arr,0,sizeof(int)*len);

    lnode* p= head->next;
    int pos =0;
    while(p!=0)         //$p, arr;  pos
    {                   //update arr
        arr[pos] = p->data;
        pos++;p=p->next;
    }

    quicksort(arr,len);

    p= head->next;pos=0;
    while(p!=0)         //$p, arr;  pos
    {                   //update head
        p->data = arr[pos];
        pos++;p=p->next;
    }

    delete[] arr;           //销毁
}

void mergeList(lnode* a, lnode* b,lnode* c)
{
    if(a==0||b==0||c==0) return ;
    
    lnode*pa =a->next, *pb=b->next,*pc=c;

    while(pa!=0&&pb!=0)     //pa, pb ,pc
    {
        if(pa->data > pb->data)
        {
            pc->next = pb;
            pc = pb;        //update pb,pc
            pb=pb->next;       
        }
        else
        {
            pc->next = pa;
            pc = pa;         //update pa,pc
            pa=pa->next;
        }
    }
    if(pa!=0) pc->next = pa;
    if(pb!=0) pc->next = pb;
}

void bucketsort(int arr[],int len,int bucketnum=3)
{
    if(arr==0||len<2) return;

    lnode* lists[bucketnum];

    for(int i=0;i<bucketnum;i++)        //初始化链表
        lists[i] = initList();
    
    int bucket =0;
    for(int i=0;i<len;i++)             //arr to list
    {
        bucket = arr[i]%bucketnum;
        pushOrder(lists[bucket],arr[i]);    //插入排序
    }

    // for(int i=0;i<bucketnum;i++)       //sort all lists
    //     listsort(lists[i]);
    
    // for(int i=0;i<bucketnum;i++)  
    //     {
    //         cout << "list[" << i << "]:" ;
    //         printList(lists[i]);
    //     }

    lnode* result = initList();
    for(int i=0;i<bucketnum;i++)  //merge lists
    {
        mergeList(result,lists[i],result);
        //printList(result);
    }

    // cout << "result:" <<endl;
    // printList(result);

    lnode* p = result->next;
    int pos =0;
    while(p!=0&&pos<len)        //list to arr
    {
        arr[pos++] = p->data;
        p = p->next;
    }

    for(int i=0;i<bucketnum;i++)   //销毁链表
        destroyList(lists[i]);
    destroyList(result);
}

int main()
{
    int arr[] = { 44,3,38,5,47,5,36,26,27,2,46,4,19,50,48 };   // 待排序的数组。
    int len = sizeof(arr) / sizeof(int);    // 求数组长度。

    cout << "\t\t\t\tbucketsort" <<endl;
    cout << "before sort:" <<endl;
    for(int i=0;i<len;i++) 
    {
        cout << "arr[" << i << "]=" << arr[i] << "\t";
        if((i+1)%5==0) cout <<endl;
    }
    cout <<endl;

    bucketsort(arr,len,3);
    cout << "after sort:" <<endl;
    for(int i=0;i<len;i++) 
    {
        cout << "arr[" << i << "]=" << arr[i] << "\t";
        if((i+1)%5==0) cout <<endl;
    }
    cout <<endl;
}
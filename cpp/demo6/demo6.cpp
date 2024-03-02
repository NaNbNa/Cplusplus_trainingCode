#include <iostream>

using namespace std;

struct st_girl
{
    int no;
    string name;
    struct st_girl* next;
};
int main()              //链表
{
    st_girl* head = nullptr, *tail = nullptr, *tmp = nullptr;

    tmp = new st_girl({1,"西施", nullptr});

    head = tail  = tmp;

    tmp = new st_girl({6, "冰冰",nullptr});
    tail -> next = tmp;
    tail = tmp;

    tmp = new st_girl({3, "咪咪",nullptr});
    tail -> next = tmp;
    tail = tmp;

    tmp = head;
    while(tmp!=nullptr)   //print table
    {
        cout << "no=" << tmp->no << ", name = " << tmp ->name <<", tmp->next = " << tmp->next <<endl;
        tmp = tmp->next;
    }

    while(head != nullptr)  //delelte table
    { 
        tmp = head;
        head = head ->next;
        delete tmp;
    }
}
#include <iostream>
#include <string.h>

using namespace std;           //模板类

//typedef string elem;

template <class elem>
class stack
{

private:
    elem* items;
    int stacksize;
    int top;    
public:
    stack(int size):stacksize(size),top(0)
    {
        items = new elem[stacksize];
    }
    ~stack()
    {
        delete[] items;items=nullptr;       
    }
    bool isempty() const
    {
        // if(top==0) return true;
        // return false;

        return top==0;
    }
    bool isfull() const
    {
        return top==stacksize;
    }
    bool push(const elem& item)
    {
        if(top<stacksize)
        {
            items[top++] = item;
            return true;
        }
        return false;
    }
    bool pop(elem& item)
    {
        if(top>0)
        {
            item = items[--top];
            return true;
        }
        return false;
    }
};

int main()
{
    stack<string> ss(5);
    ss.push("1");ss.push("2");ss.push("3");ss.push("4");ss.push("5");

    string item;
    while(ss.isempty()==false)
    {
        ss.pop(item);
        cout << "item=" << item <<endl;
    }

}
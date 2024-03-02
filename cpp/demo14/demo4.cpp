#include <iostream>
#include <string.h>

using namespace std;

template <class T>
class stack1
{
private:
    T* items; 
    int top;
    int stacksize;
public:
    stack1(int size=3):stacksize(size)
    {
        items = new T[stacksize];
    }
    ~stack1()
    {
        delete[] items;items = nullptr;
    }

    stack1& operator=(const stack1& v)
    {
        if(&v == this) return *this;
        
        delete[] items; items = nullptr;
        stacksize=v.stacksize;
        top=v.top;

        if(v.items!=nullptr)
        {
            items = new T[stacksize];
            for(int i=0;i<stacksize;i++)
                items[i] = v.items[i];
        }

        return *this;
    }

    bool isempty()
    {
        return top==0;
    }
    bool isfull()
    {
        return top==stacksize;
    }

    bool push(const T& elem)
    {
        if(top< stacksize)
        {
            items[top++] = elem;
            return true;
        }
        return false;
    }

    bool pop(T& elem)
    {
        if(top>0)
        {
            elem = items[--top];
            return true;
        }
        return false;
    }
};

template <typename T>
class vertor1
{
private:
    T* items;
    int len;
public:
    vertor1(int size=2):len(size)
    {
        items = new T[len];
        //memset(items,0,sizeof(T)*len)
    }
    ~vertor1()
    {
        delete[] items; items = nullptr;
    }
    vertor1& operator=(const vertor1& v)
    {
        if(&v== this) return *this;

        delete[] items;items = nullptr;
        len = v.len;
        
        if(v.items!=nullptr)
        {
            items = new T[len];
            for(int i=0;i<len;i++)
                items[i] = v.items[i];
        }

        return *this;
    }
    void resize(int size)
    {
        if(size<=len) return;

        T* temp = new T[size];
        for(int i=0;i<len;i++) temp[i] = items[i]; //如果是浅拷贝,不是深拷贝会出现问题

        delete[] items;
        items = temp;
        len = size;
    }

    int size()
    {
        return len;
    }
    T& operator[](int i)
    {
        if(i>len-1)  resize(i+1);
        return items[i];
    }

    const T& operator[](int ii) const
    {
        return items[ii];
    }
};

int main()
{
    // vertor1<stack1<string>> vs;
    // // stack1<string> vs1[2];   //帮助理解的
    // // string vs3[2][3];

    // vs[0].push("西施1");vs[0].push("西施2");vs[0].push("西施3");
    // vs[1].push("西瓜1");vs[1].push("西瓜2");vs[1].push("西瓜3");
    // vs[2].push("冰冰1");vs[2].push("冰冰2");vs[2].push("冰冰3");

    // string item;
    // for(int i=0;i<vs.size();i++)
    // {
    //     while(vs[i].isempty()==false)
    //     {
    //         vs[i].pop(item);
    //         cout << "item=" << item <<endl;
    //     }
    // }

    // stack1<vertor1<string>> sv;

    // vertor1<string> temp;
    // temp[0]="西施1";temp[1]="西施2";sv.push(temp);
    // temp[0]="西瓜1";temp[1]="西瓜2";sv.push(temp);
    // temp[0]="冰冰1";temp[1]="冰冰2";temp[2]="冰冰3";temp[3]="冰冰4";sv.push(temp);

    // while(sv.isempty()==false)
    // {
    //     sv.pop(temp);
    //     for(int i=0;i<temp.size();i++)
    //     {
    //         cout << "vertor[" << i << "]=" << temp[i] <<endl;
    //     }
    // }

    vertor1<vertor1<string>> vv;

    vv[0][0] = "西施1";vv[0][1] = "西施2";vv[0][2] = "西施3";
    vv[1][0] = "西瓜1";vv[1][1] = "西瓜2";
    vv[2][0] = "冰冰1";vv[2][1] = "冰冰2";vv[2][2] = "冰冰3";vv[2][3] = "冰冰4";

    for(int i=0;i<vv.size();i++)
    {
        for(int j=0;j<vv[i].size();j++)
        {
            cout << "vv[" << i << "][" << j << "]=" << vv[i][j] <<"\t";
        }
        cout <<endl;
    }
}
#ifndef __PUBLIC_HH
#define __PUBLIC_HH 1

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>
using namespace std;

template <class T,int MaxLength>
class squeue
{
private: 
    T m_data[MaxLength];
    int m_head;
    int m_tail;
    int m_length;
    squeue(const squeue &) = delete;
    squeue &operator()(const squeue&) = delete;
public:
    squeue(){ init();}
    bool m_inited;
    void init()
    {
        if(m_inited==false)
        {
            m_head = 0;
            m_tail = MaxLength -1;
            m_length = 0;
            memset(m_data,0,sizeof(m_data));
            m_inited = true;
        }
    }

    bool full()
    {
        return m_length == MaxLength;
    }
    int size()
    {
        return m_length;
    }
    bool empty()
    {
        return m_length ==0;
    }
    bool push(const T& ee)
    {
        if(full()==true)
            {
                cout << "full,can't push" <<endl;
                return false;}
        
        m_tail = (m_tail+1)%MaxLength;
        m_data[m_tail] = ee;
        m_length++;
        return true;
    }
    T& front()
    {
        return m_data[m_head];
    }

    bool pop()
    {
        if(empty()==true) 
        {
            cout << "empty,can't pop" <<endl;
            return false;}

        m_head = (m_head+1)% MaxLength;
        m_length --;

        return true;
    }
    void printqueue()
    {
        int pos;
        for(int ii=0;ii<m_length;ii++)
        {
            pos = (m_head+ii)%MaxLength;
            cout << "m_data[" << pos << "], value=" 
            << m_data[pos] <<endl;
        }
    }
};

class csemp
{
private:
    union semun
    {
        int val;
        struct semid_ds *buf;
        unsigned short *arry;
    };

    int m_semid;
    short m_sem_flg;

    csemp(const csemp&) =delete;
    csemp& operator()(const csemp&) =delete;
public:
    csemp():m_semid(-1){}

    bool init(key_t key,unsigned short value=1,short sem_flg =SEM_UNDO);
    bool wait(short sem_op=-1);
    bool post(short sem_op=1);
    int  getvalue(); 
    bool destroy();
    ~csemp();
};
#endif
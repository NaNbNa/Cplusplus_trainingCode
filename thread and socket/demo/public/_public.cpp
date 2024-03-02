#include "_public.h"


bool csemp::init(key_t key,unsigned short value,short sem_flg)
{
    if(m_semid!=-1) return false;

    m_sem_flg = sem_flg;

    if((m_semid = semget(key,1,0666))==-1)
    {
        if(errno==ENOENT)
        {
            if((m_semid=semget(key,1,0666|IPC_CREAT|IPC_EXCL))==-1)
            { 
                if(errno==EEXIST)
                {
                    if((m_semid=semget(key,1,0666))==-1)
                    {
                        perror("init 1 semge()");
                        return false;
                    }
                    return true;
                }
                else
                {
                    perror("init 2 semget()");return false;
                }
            }

            union semun sem_union;
            sem_union.val = value;   // 设置信号量的初始值。
            if (semctl(m_semid,0,SETVAL,sem_union) <  0) 
            { 
                perror("init semctl()"); return false; 
            }
        }
        else
        {
            perror("init 3 semget()");return false;
        }
    }

    return true;
}

bool csemp::wait(short value)       //P
{
    if(m_semid==-1) return false;

    sembuf sem_b;
    sem_b.sem_num =0;
    sem_b.sem_op = value;
    sem_b.sem_flg = m_sem_flg;
    
    if(semop(m_semid,&sem_b,1)==-1){perror("p semop()"); return false;}

    return true;
}

bool csemp::post(short value)
{
    if(m_semid==-1) return false;

    sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op =value;
    sem_b.sem_flg =m_sem_flg;
    if(semop(m_semid,&sem_b,1)==-1) {perror("V semop()"); return false;}

    return true;
}

int csemp::getvalue()
{
    return semctl(m_semid,0,GETVAL);
}

bool csemp::destroy()
{
    if(m_semid==-1) return false;

    if(semctl(m_semid,0,IPC_RMID)==-1) {perror("destroy semctl()"); return false;}

    return true;
}

csemp::~csemp()
{
}

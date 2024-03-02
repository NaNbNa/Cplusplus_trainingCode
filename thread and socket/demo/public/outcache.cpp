#include "_public.h"

int main()  //模拟消费者
{
    struct stgirl
    {
        int no;
        char name[51];
    };

    using ElemType=stgirl;

    int shmid= shmget(0x5005,sizeof(squeue<ElemType,5>),0640|IPC_CREAT);
    if(shmid==-1)
    {
        cout << "shmid(0x5005) failed" <<endl;return false;
    }

    squeue<ElemType,5>* qq = (squeue<ElemType,5>*)shmat(shmid,0,0);
    if(qq==(void*)-1)
    {
        cout << "shmat() failth" <<endl; return false;
    }

    ElemType ee;

    csemp mutex;mutex.init(0x5001);
    csemp cond;cond.init(0x5002,0,0);
    csemp cond1;cond1.init(0x5003,0,0);
    while(true)
    {
        mutex.wait();

        while(qq->empty()==true)
        {
            mutex.post();
            cond.wait();
            mutex.wait();
        }

        ee = qq->front();qq->pop();
        mutex.post();


        cout << "消费者进程"<< getpid() << ": 消费了:no=" << ee.no << ", name=" << ee.name <<endl;
        sleep(1);

        cond1.post(1);
    }
    
    shmdt(qq);
}

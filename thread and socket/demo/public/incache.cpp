#include "_public.h"

int main()      //生产者
{
    struct stgirl
    {
        int no;
        char name[51];
    };

    using ElemType=stgirl;

    int shmid = shmget(0x5005,sizeof(squeue<ElemType,5>),0640|IPC_CREAT);
    if(shmid==-1)
    {
        cout <<"shmget(0x5005) failed" <<endl;return false;
    }

    squeue<ElemType,5> *qq = (squeue<ElemType,5>*)shmat(shmid,0,0);
    if(qq==(void*)-1)
    {
        cout << "shmat() failed" <<endl;return false;
    }

    qq->init();

    ElemType ee;
    string str1 = to_string(getpid());
    string str;
    
    csemp mutex;mutex.init(0x5001);
    csemp cond;cond.init(0x5002,0,0);
    csemp cond1;cond1.init(0x5005,0,0);
    int i =0;
    while(true)
    {
        i++;
        mutex.wait();
        while(qq->full()==true)
        {
            mutex.post();
            cond1.wait();
            mutex.wait();
        }

        sleep(1);
        str = str1 + ":第"+to_string(i) + "号-西施";
        ee.no = i;strcpy(ee.name,str.c_str());
        if(qq->push(ee))
            cout << "生产者进程:" << getpid() << "生产了" << ee.name <<endl;
        sleep(1);
        
        str = str1 + ":第"+to_string(i) + "号-冰冰";
        ee.no = i;strcpy(ee.name,str.c_str());
        if(qq->push(ee))
            cout << "生产者进程:" << getpid() << "生产了" << ee.name <<endl;
        sleep(1);

        str = str1 + ":第"+to_string(i) + "号-咪咪";
        ee.no = i;strcpy(ee.name,str.c_str());
        if(qq->push(ee))
            cout << "生产者进程:" << getpid() << "生产了" << ee.name <<endl;

        mutex.post();
        cond.post(3); 
    }
  
    shmdt(qq);
}
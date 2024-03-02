#include "_public.h"

struct stgirl
{
  int no;
  char name[51];  
};

int main(int argc,char* argv[])     //测试互斥锁
{
    if(argc!=3) {cout << "Using: ./demo no name" <<endl; return -1;}

    int shmid  = shmget(0x5005,sizeof(stgirl),0640|IPC_CREAT);
    if(shmid==-1)
    {
        cout << "shmget(0x5005) failed" <<endl;return -1;
    }

    cout << "shmid=" << shmid  <<endl;
    stgirl *ptr =(stgirl*)shmat(shmid,0,0);
    if(ptr==(void*)-1)
    {
        cout << "shmat() failed" <<endl;return -1;
    }

    csemp mutex;
    if(mutex.init(0x5005)==false)
    {
        cout << "mutex.init(0x5005) failed" <<endl; return -1;
    }

    cout << "申请加锁" <<endl;
    mutex.wait();
    cout << "加锁成功" <<endl;

    cout << "原值: no=" << ptr->no  << ", name=" << ptr->name <<endl;
    ptr->no = atoi(argv[1]);
    strcpy(ptr->name,argv[2]);
    cout << "新值: no=" << ptr->no << ", name =" << ptr->name <<endl;
    sleep(10);

    mutex.post();
    cout << "解锁" <<endl;

    shmdt(ptr); 

} 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
using namespace std;    //共享内存

struct stgirl
{
    int no;
    //char name[51];
    string name;
};
int main(int argc,char* argv[])
{
    if(argc!=3) {cout << "Using ./demo no name" <<endl; return -1;}

    int shmid = shmget(0x5005,sizeof(stgirl),0640|IPC_CREAT);
    if(shmid==-1)
    { 
        cout << "shmid(0x5005) failed" <<endl;
    }

    cout << "shmid=" <<shmid <<endl;

    stgirl *ptr = (stgirl*) shmat(shmid,0,0);
    if(ptr==(void*)-1)
    {
        cout << "shmat() failed" <<endl; return -1;
    }

    cout << "原值: no="<< ptr->no << ", name=" << ptr->name <<endl;
    ptr->no = atoi(argv[1]);
    //strcpy(ptr->name,argv[2]);
    ptr->name = argv[2];    //Segmentation fault,因为共享内存不支持string（堆区内存）

    cout << "新值: no=" << ptr->no << ", name=" << ptr->name <<endl;

    shmdt(ptr);

    // if(shmctl(shmid,IPC_RMID,0)==-1)
    // {
    //     cout << "shmctl failed" <<endl;return -1;
    // }
    // else
    //     cout << "shmctl success"<<endl;
}
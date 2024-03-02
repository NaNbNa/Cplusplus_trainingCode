#include "_public.h"

int main()  //创建循环队列的共享内存
{
    using ElemType=int;

    int shmid = shmget(0x50005,sizeof(squeue<ElemType,5>),0640|IPC_CREAT);
    if(shmid==-1){cout << "shmget(0x5005) failed" <<endl; return -1;}

    //不会调用squeue构造函数
    squeue<ElemType,5> *qq = (squeue<ElemType,5>*)shmat(shmid,0,0); 
    if(qq==(void*)-1){cout << "shmat() failed" << endl;return -1;}

    
    qq->init();

    ElemType ee;
    cout << "入队(1,2,3)" <<endl;
    ee =1;qq->push(ee);
    ee =2;qq->push(ee);
    ee =3;qq->push(ee);

    cout << "队列的长度是" << qq->size() <<endl;
    qq->printqueue();

    ee =qq->front();qq->pop();cout << "出队的元素是: " << ee <<endl;
    ee =qq->front();qq->pop();cout << "出队的元素是: " << ee <<endl;
    cout << "队列的长度是" << qq->size() <<endl;
    qq->printqueue();

    cout << "入队(11,12,13,14,15)" <<endl;
    ee =11;qq->push(ee);
    ee =12;qq->push(ee);
    ee =13;qq->push(ee);
    ee =14;qq->push(ee);
    ee =15;qq->push(ee);

    cout << "队列的长度是: " << qq->size() <<endl;
    qq->printqueue();

    shmdt(qq);
}
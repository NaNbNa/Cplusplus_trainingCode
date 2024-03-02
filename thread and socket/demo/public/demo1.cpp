#include "_public.h"

int main()      //测试循环队列
{
    using ElemType= int;

    squeue<ElemType,5> qq;

    ElemType ee;
    cout << "入队(1,2,3)" <<endl;
    ee =1;qq.push(ee);
    ee =2;qq.push(ee);
    ee =3;qq.push(ee);

    cout << "队列的长度是" << qq.size() <<endl;
    qq.printqueue();

    ee =qq.front();qq.pop();cout << "出队的元素是: " << ee <<endl;
    ee =qq.front();qq.pop();cout << "出队的元素是: " << ee <<endl;

    cout << "队列的长度是: " << qq.size() <<endl;
    qq.printqueue();

    cout << "入队(11,12,13,14,15)" <<endl;
    ee =11;qq.push(ee);
    ee =12;qq.push(ee);
    ee =13;qq.push(ee);
    ee =14;qq.push(ee);
    ee =15;qq.push(ee);

    cout << "队列的长度是: " << qq.size() <<endl;
    qq.printqueue();
}
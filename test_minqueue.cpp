#include<iostream>
using namespace std;
#include "minqueue.cpp"

int main(){
    int *arrTest = new int[0];
    MinQueue pQueue = MinQueue(0, 0, arrTest);
    pQueue.insert(4);
    pQueue.insert(1);
    pQueue.insert(3);
    pQueue.insert(5);
    pQueue.insert(16);
    pQueue.insert(9);
    pQueue.insert(10);
    pQueue.insert(14);
    pQueue.insert(8);
    pQueue.insert(7);

    printArr(pQueue.heapBase.arrValue, pQueue.heapBase.size);
    cout<<pQueue.minimum()<<endl;
    pQueue.decrease_key(7, 2);
    cout<<"After decrease key:"<<endl;
    printArr(pQueue.heapBase.arrValue, pQueue.heapBase.size);
    // arrTest[0] = 1;
    // arrTest[1] = 2;
    // arrTest[2] = 3;
    // printArr(arrTest,3);
    
}
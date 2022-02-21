#include<iostream>
using namespace std;
#include "minqueue.cpp"

int main(){
    int *arrTest = new int[0];
    MinQueue pQueue = MinQueue();
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
    cout<<"Min number:"<<endl;
    cout<<pQueue.minimum()<<endl;
    pQueue.decrease_key(7, 2);
    cout<<"After decrease key:"<<endl;
    printArr(pQueue.heapBase.arrValue, pQueue.heapBase.size);
    pQueue.extract_min();
    cout<<"After extract"<<endl;
    printArr(pQueue.heapBase.arrValue, pQueue.heapBase.size);
    cout<<"Sort the priority queue:"<<endl;
    heap_sort(pQueue.heapBase);
    printArr(pQueue.heapBase.arrValue, pQueue.heapBase.size);
}
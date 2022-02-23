#include<iostream>
using namespace std;
#include "minqueue.cpp"
#include "utility.cpp"

int main(){

    //Double data type
    MinQueue<double> pQueue = MinQueue<double>();
    pQueue.insert(4.5);
    pQueue.insert(1.6);
    pQueue.insert(3.8);
    pQueue.insert(5.9);
    pQueue.insert(16.3);
    pQueue.insert(9.2);
    pQueue.insert(10.3);
    pQueue.insert(14.1);
    pQueue.insert(8.4);
    pQueue.insert(7.9);
    //test priority queue after inserting
    printArr(pQueue.heapBase.arrValue, pQueue.heapBase.size);
    //minimum element in the priority queue
    cout<<"Min number:"<<endl;
    cout<<pQueue.minimum()<<endl;
    //test decrease_key 
    pQueue.decrease_key(7, 3.1);
    cout<<"After decrease key:"<<endl;
    printArr(pQueue.heapBase.arrValue, pQueue.heapBase.size);
    //test extract_min
    pQueue.extract_min();
    cout<<"After extract"<<endl;
    printArr(pQueue.heapBase.arrValue, pQueue.heapBase.size);
    //test heap_sort build_min_heap and heapify (since build_min_heap and heapify are in heap_sort)
    pQueue.heapBase.heap_sort();
    cout<<"Sort the priority queue:"<<endl;
    printArr(pQueue.heapBase.arrValue, pQueue.heapBase.size);

    cout<<endl;
    //Int data type
    MinQueue<int> pQueueInt = MinQueue<int>();
    pQueueInt.insert(12);
    pQueueInt.insert(2);
    pQueueInt.insert(10);
    pQueueInt.insert(7);
    pQueueInt.insert(4);
    pQueueInt.insert(9);
    pQueueInt.insert(1);
    pQueueInt.insert(8);
    pQueueInt.insert(3);
    pQueueInt.insert(15);
    //test priority queue after inserting
    printArr(pQueueInt.heapBase.arrValue, pQueueInt.heapBase.size);
    //minimum element in the priority queue
    cout<<"Min number:"<<endl;
    cout<<pQueueInt.minimum()<<endl;
    // test decrease_key 
    pQueueInt.decrease_key(9,6);
    cout<<"After decrease key:"<<endl;
    printArr(pQueueInt.heapBase.arrValue, pQueueInt.heapBase.size);
    // test extract_min
    pQueueInt.extract_min();
    cout<<"After extract"<<endl;
    printArr(pQueueInt.heapBase.arrValue, pQueueInt.heapBase.size);
    //test heap_sort build_min_heap and heapify (since build_min_heap and heapify are in heap_sort)
    pQueueInt.heapBase.heap_sort();
    cout<<"Sort the priority queue:"<<endl;
    printArr(pQueueInt.heapBase.arrValue, pQueueInt.heapBase.size);
 
}
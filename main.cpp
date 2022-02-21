#include<iostream>
using namespace std;
#include "minqueue.cpp"

MinQueue cpyArrToMinPQueue(int* arr, int start, int len){
    MinQueue pq;
    for (int i = start; i<start+len; i++){
        pq.insert(arr[i]);
    }
    cout<<"Min Queue arr:"<<endl;
    printArr(pq.heapBase.arrValue,3);
    return pq;
}

//Might need to improve since running time now is O(n^2)
int *windowPosition(int *inputArr, int k){
    int *returnArr = new int[6]; 
    int size = 8;
    MinQueue minPQ;
    for (int i=0; i<size-2; i++){
        minPQ = cpyArrToMinPQueue(inputArr, i, k); 
        returnArr[i] = minPQ.heapBase.arrValue[0]; 
    }
    return returnArr;
    
}
int main(){
    int inputArr[8] = {1,3,-1,-3,5,3,6,7};
    int *testArr = windowPosition(inputArr,3);
    cout<<"result:"<<endl;
    printArr(testArr,6);
}
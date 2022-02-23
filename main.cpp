#include <iostream>
using namespace std;
#include "minqueue.cpp"

//create a minQueue based on the given array
template<typename T>
MinQueue<T> cpyArrToMinPQueue(T *arr, int start, int len)
{
    MinQueue<T> pq;
    for (int i = start; i < start + len; i++)
    {
        pq.insert(arr[i]);
    }
    return pq;
}

//inputArr is the given array, k is the size of the window, s is the size of inputArr
template<typename T>
T *windowPosition(T *inputArr, int k, int s)
{
    T *returnArr = new T[s - k + 1];
    MinQueue<T> minPQ;
    for (int i = 0; i < s - k + 1; i++)
    {
        minPQ = cpyArrToMinPQueue(inputArr, i, k);
        returnArr[i] = minPQ.heapBase.arrValue[0];
    }
    return returnArr;
}
int main()
{
    int inputArr[8] = {1, 3, -1, -3, 5, 3, 6, 7};
    int *testArr = windowPosition(inputArr, 3,8);
    //size testArr is 6 since the window size is 3. So the maximum number of windows is 6
    printArr(testArr, 6);

    // int inputArr[8] = {3, 5, -1, 2, 8, 9, 7, 1};
    // int *testArr = windowPosition(inputArr, 4, 8);
    // printArr(testArr, 5);
}
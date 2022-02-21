#include <iostream>
using namespace std;
#include "minqueue.cpp"

MinQueue cpyArrToMinPQueue(int *arr, int start, int len)
{
    MinQueue pq;
    for (int i = start; i < start + len; i++)
    {
        pq.insert(arr[i]);
    }
    cout << "Min Queue arr:" << endl;
    printArr(pq.heapBase.arrValue, 3);
    return pq;
}

// Might need to improve since running time now is O(n^2)
// k is the size of the box, s is the size of inputArr
int *windowPosition(int *inputArr, int k, int s)
{
    int *returnArr = new int[s - k + 1];
    MinQueue minPQ;
    for (int i = 0; i < s - k + 1; i++)
    {
        minPQ = cpyArrToMinPQueue(inputArr, i, k);
        returnArr[i] = minPQ.heapBase.arrValue[0];
    }
    return returnArr;
}
int main()
{
    /*int inputArr[8] = {1, 3, -1, -3, 5, 3, 6, 7};
    int *testArr = windowPosition(inputArr, 3);
    cout << "result:" << endl;
    printArr(testArr, 6);*/

    int inputArr[10] = {3, 5, -1, 2, 8, 9, 7, 1};
    int *testArr = windowPosition(inputArr, 5, 8);
    cout << "result:" << endl;
    printArr(testArr, 4);
}
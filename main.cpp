#include <iostream>
using namespace std;
#include "minqueue.cpp"
#include "utility.cpp"

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
        //each time we create a minQueue to a sliced array
        minPQ = cpyArrToMinPQueue(inputArr, i, k);
        //the first element of the minQueue (the smallest element) will be added to the returnArr
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

    //Other test cases:
    cout<<"Other test cases: "<<endl;
    int inputArr1[8] = {3, 5, -1, 2, 8, 9, 7, 1};
    int *testArr1 = windowPosition(inputArr1, 4, 8);
    //size testArr is 8 since the window size is 4. So the maximum number of windows is 5
    printArr(testArr1, 5);

    int inputArr2[10] = {2,7,-1,4,6,10,5,11,3,-2};
    int *testArr2 = windowPosition(inputArr2, 5, 10);
    //size testArr is 10 since the window size is 5. So the maximum number of windows is 6
    printArr(testArr2, 6);

}
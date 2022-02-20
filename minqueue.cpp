#include<iostream>
#include<vector>
using namespace std;


class MinHeap{
    public: 
        int *arrValue;
        int capacity;
        int size;
    MinHeap(int capacity, int arr[], int s){
        capacity = capacity;
        size = s;
        arrValue = arr;
    }
        int findParent(int i){
            return (i-1)/2;
        }
        int findLeft(int i){
            return 2*i+1;
        }
        int findRight(int i){
            return 2*i+2;
        }
        void swap(int const &a, int const &b){
            int temp = arrValue[a];
            arrValue[a] = arrValue[b];
            arrValue[b] = temp;
        }
        void heapify(int i);
        void build_min_heap();
        int* heap_sort();
};

void MinHeap::heapify(int i){
    int smallest = i;
    int l = findLeft(i);
    int r = findRight(i);   
    if (l < size && arrValue[l] < arrValue[i]){
        smallest = l;
    }
    if (r < size && arrValue[r] < arrValue[smallest]){
        smallest = r;
    }
    if (smallest != i){
        swap(smallest, i);
        heapify(smallest);
    }
}

void MinHeap::build_min_heap(){
    for (int i = (size/2)-1; i>=0; i--){
        heapify(i);
    }
}

void printArr(int arr[], int size){
    cout<<"In the arr:"<<endl;
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<endl;
    }
}

int* heap_sort(MinHeap heap){
    int* sortedArr = new int[heap.size];
    int originalSize = heap.size;
    for (int i=heap.size-1; i>0; i--){
        heap.swap(i, 0);
        cout<<"Last element of arrValue after swap: "<<heap.arrValue[i]<<endl;
        sortedArr[originalSize-1-i] = heap.arrValue[i];
        // printArr(heap.arrValue,10);
        heap.size -= 1;
        // cout<<heap.size<<endl;
        heap.heapify(0);
    }
    sortedArr[originalSize - 1] = heap.arrValue[0];
    return sortedArr;
}
int main(){
    //create an input array for heap
    int arr_cpy[10] = {4,1,3,2,16,9,10,14,8,7};
    int *arr = new int[20];
    for (int i =0; i<10; i++){
        arr[i] = arr_cpy[i];
    }
    //end array

    //create heap
    MinHeap heap = MinHeap(20,arr, 10);
    heap.build_min_heap();
    //test heap_min by printing the array
    for (int i =0; i<heap.size; i++){
        cout<<heap.arrValue[i]<<endl;
    }

    //sort the heap
    int *arrSort = heap_sort(heap);
    printArr(arrSort,10);
    return 0;
}
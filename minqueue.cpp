#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class MinHeap{
    public: 
        int *arrValue;
        int capacity;
        int size;
        MinHeap(){
            arrValue = nullptr;
            capacity = 0;
            size = 0;
        }
        MinHeap(int capacity, int *arr, int s){
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
        //parameters are indices
        void swap(int const &a, int const &b){
            int temp = arrValue[a];
            arrValue[a] = arrValue[b];
            arrValue[b] = temp;
        }
        void shallowCpy(int*arr, int*cpyArr, int size){
            for (int i = 0; i<size; i++){
                arr[i] = cpyArr[i];
            }
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
        sortedArr[originalSize-1-i] = heap.arrValue[i];
        heap.size -= 1;
        heap.heapify(0);
    }
    sortedArr[originalSize - 1] = heap.arrValue[0];
    //update the heap.arrValue to sortedArr
    heap.shallowCpy(heap.arrValue, sortedArr, originalSize);
    heap.size = originalSize;
    heap.capacity = heap.size;
    return sortedArr;
}

//MinQueue
class MinQueue{
    public:
        MinHeap heapBase;
        MinQueue();
        int minimum();
        int extract_min();
        void decrease_key(int, int);
        void insert(int);
};

MinQueue::MinQueue(){
    heapBase = MinHeap(0,new int[0],0);
}
int MinQueue::minimum(){
    return heapBase.arrValue[0];
}

int MinQueue::extract_min(){
    swap(heapBase.arrValue[0], heapBase.arrValue[heapBase.size-1]);
    int minVal = heapBase.arrValue[heapBase.size-1];
    heapBase.size -= 1;
    heapBase.heapify(0);
    return minVal;
}

void MinQueue::decrease_key(int index, int newVal){
    if (newVal > heapBase.arrValue[index]){
        cout<<"Cannot decrease x to a bigger value"<<endl;
        return;
    }
    heapBase.arrValue[index] = newVal;
    int i = index;
    while(i>0 && heapBase.arrValue[heapBase.findParent(i)]>heapBase.arrValue[i]){
        heapBase.swap(i,heapBase.findParent(i));
        i = heapBase.findParent(i);
    }
}

void MinQueue::insert(int newVal){
    heapBase.arrValue[heapBase.size] = INT_MAX;
    heapBase.size += 1;
    decrease_key(heapBase.size-1, newVal);
}

// int main(){
//     //create an input array for heap
//     int arr_cpy[10] = {4,1,3,2,16,9,10,14,8,7};
//     int *arr = new int[20];
//     for (int i =0; i<10; i++){
//         arr[i] = arr_cpy[i];
//     }
//     //end array

//     //create heap
//     MinHeap heap = MinHeap(20,arr, 10);
//     heap.build_min_heap();
//     //test heap_min by printing the array
//     for (int i =0; i<heap.size; i++){
//         cout<<heap.arrValue[i]<<endl;
//     }

//     //sort the heap
//     int *arrSort = heap_sort(heap);
//     printArr(heap.arrValue,10);

//     return 0;
// }
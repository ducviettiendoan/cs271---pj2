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
    return 0;
}
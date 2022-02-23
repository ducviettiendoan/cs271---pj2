#include<iostream>
#include<climits>
using namespace std;

//class minHeap for minQueue class later
template<typename T>
class MinHeap{
    public: 
        //an array to hold all the values of the heap
        T *arrValue;
        //array capacity
        int capacity;
        //size of heap
        int size;

        //Heap's Constructors 
        MinHeap();
        MinHeap(int, T*, int );
        MinHeap(const MinHeap &);
        //index of parent, left child, or right child
        int findParent(int i){
            return (i-1)/2;
        }
        int findLeft(int i){
            return 2*i+1;
        }
        int findRight(int i){
            return 2*i+2;
        }
        //swap 2 elements in an array
        void swap(int const &, int const &);
        //heapify to maintain the minHeap property
        void heapify(int i);
        // build a min heap 
        void build_min_heap();
        //heap sort algorithm
        void heap_sort();

};

template<typename T>
MinHeap<T>::MinHeap(){}

template<typename T>
MinHeap<T>::MinHeap(int capacity, T *arr, int s){
    capacity = capacity;
    size = s;
    arrValue = arr;
}

//deep copy a minHeap to another minHeap
template<typename T>
MinHeap<T>::MinHeap(const MinHeap &heap){
    cout<<"Size:"<<heap.size<<endl;
    arrValue = new T[heap.size];
    //deep copy the array
    for (int i =0; i<heap.size; i++){
        arrValue[i] = heap.arrValue[i];
    }
    capacity = heap.capacity;
    size = heap.size;
}

template<typename T>
void MinHeap<T>::swap(int const &a, int const &b){
    //parameters are indices
    T temp = arrValue[a];
    arrValue[a] = arrValue[b];
    arrValue[b] = temp;
}

//precondition: the smallest number of each subtree is swapped or stay the same for next heapify() call
//postcondition: each subtree always maintain the min-heap property after heapify()
template<typename T>
void MinHeap<T>::heapify(int i){
    int smallest = i;
    int l = findLeft(i);
    int r = findRight(i);   
    if (l < size && arrValue[l] < arrValue[i]){
        smallest = l;
    }
    if (r < size && arrValue[r] < arrValue[smallest]){
        smallest = r;
    }
    //if swap elements call heapify again to maintain the minHeap property
    if (smallest != i){
        swap(smallest, i);
        heapify(smallest);
    }
}

//precondition: the heap contains elements inorder to be heapify()
//postcondition: By continuously calling heapify() for each subtree, the final heap is now a min-heap.
template<typename T>
void MinHeap<T>::build_min_heap(){
    //heapify all the subtrees 
    for (int i = (size/2)-1; i>=0; i--){
        heapify(i);
    }
}

//precondition: before each implementation of heap_sort, the heap is a min-heap (has min-heap properties)
//postcondition: the heap is sorted in an ascending order.
template<typename T>
void MinHeap<T>::heap_sort(){
    //make a deep copy of the input and put this copy to create a heap
    MinHeap<T> heapCpy = MinHeap<T>(*this);
    // cout<<"Before build min heap:"<<endl;
    // printArr(heapCpy.arrValue,size);
    heapCpy.build_min_heap();
    // cout<<"Build min heap:"<<endl;
    // cout<<"heapCpy:"<<endl;
    // printArr(heapCpy.arrValue,size);
    // cout<<"arrValue:"<<endl;
    // printArr(arrValue, size);
    for (int i=size-1; i>0; i--){
        heapCpy.swap(i, 0);
        arrValue[size-1-i] = heapCpy.arrValue[i];
        //pop out the last element
        heapCpy.size -= 1;
        //heapify the remaining heap after swapping
        heapCpy.heapify(0);
    }
    //get last element of minHeap to the inputArr
    arrValue[size - 1] = heapCpy.arrValue[0];
}

//MinQueue
template<typename T>
class MinQueue{
    public:
        //a heap inside the minQueue
        MinHeap<T> heapBase;
        //Contructor
        MinQueue();
        //find the minimum of a priority min queue
        T minimum();
        //extract and return the minimum value
        T extract_min();
        //decrease a value in the queue to another lower value
        void decrease_key(int, T);
        //insert the new value to the queue
        void insert(T);
};

template<typename T>
MinQueue<T>::MinQueue(){
    heapBase = MinHeap<T>(0,new T[0],0);
}

//precondition: the top (1st element of the heap) is always the smallest number
//postcondition: get the smallest number correctly
template<typename T>
T MinQueue<T>::minimum(){
    return heapBase.arrValue[0];
}

//precondition: the top (1st element of the heap) is always the smallest number
//postcondition: get the smallest number and also the heap is heapified again to maintain heap property
template<typename T>
T MinQueue<T>::extract_min(){
    //swap the min value to the end of the array
    swap(heapBase.arrValue[0], heapBase.arrValue[heapBase.size-1]);
    T minVal = heapBase.arrValue[heapBase.size-1];
    heapBase.size -= 1;
    heapBase.heapify(0);
    return minVal;
}

//precondition: the queue has the min-heap property
//postcondition: by swaping the elements after decreasing a key properly, the queue maintains the min-heap property
template<typename T>
void MinQueue<T>::decrease_key(int index, T newVal){
    if (newVal > heapBase.arrValue[index]){
        cout<<"Cannot decrease x to a bigger value"<<endl;
        return;
    }

    heapBase.arrValue[index] = newVal;
    int i = index;
    //switch the newVal with its parent if it's larger
    while(i>0 && heapBase.arrValue[heapBase.findParent(i)]>heapBase.arrValue[i]){
        heapBase.swap(i,heapBase.findParent(i));
        i = heapBase.findParent(i);
    }
}

//precondition: the queue has the min-heap property
//postcondition: similar to decrease_key, by finding the correct position for the new element 
//and swapping other elements, the queue maintains the min-heap property.
template<typename T>
void MinQueue<T>::insert(T newVal){
    //assign the value to be really large so that we could insert any number
    heapBase.arrValue[heapBase.size] = numeric_limits<T>::max();
    heapBase.size += 1;
    decrease_key(heapBase.size-1, newVal);
}

#include<iostream>
#include<climits>
using namespace std;

//ultility function to print an array (also the content of a heap) with a given size
template<typename T>
void printArr(T arr[], int size){
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

#include<iostream>

using namespace std;

void heapify(int* &arr, int n, int k){
    
    int c1 = 2 * k + 1;
    int c2 = 2 * k + 2;
    int l = k;
    if(c1 < n && arr[c1] > arr[l]) l = c1;
    if(c2 < n && arr[c2] > arr[l]) l = c2;
    if(l != k){
        swap(arr[k], arr[l]);
        heapify(arr, n, l);
    }
    
}

void buildHeap(int* arr, int n){
    for (int i = n/2 - 1; i >= 0; i--)
    heapify(arr, n, i);
}

void heapSort(int* arr, int n){
    buildHeap(arr, n);
    for(int i = n - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
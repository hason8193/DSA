#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include<math.h>
#include "SelectionSort.h"
#include"InsertionSort.h"
#include"HeapSort.h"
#include"QuickSort.h"
#include"MergeSort.h"
using namespace std;

void Tao_Mang_Cho_File(const char* file, int* arr, int n){
    ofstream ofs;
    ofs.open(file);
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 10000;
        ofs << arr[i] << " ";
    }
    ofs.close();
}

void Doc_Mang_Tu_File(const char* file, int* arr, int n){
    ifstream ifs;
    ifs.open(file);
    if (ifs.is_open()){
        for(int i = 0; i < n; i++){
            ifs >> arr[i];
        }
        ifs.close();
    }
}

void Xuat_Mang(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap n:";
    cin >> n;
    int* arr = new int[n];
    const char* file = "random_numbers.txt";
    Tao_Mang_Cho_File(file, arr, n);
    Doc_Mang_Tu_File(file, arr, n);
    long start1 = clock();
    Selection_Sort(arr, n);
    long end1 = clock();
    cout << "Thoi gian thuc hien cua Selection Sort la: " << end1 - start1 << " giay" << endl;
    long start2 = clock();
    Insertion_Sort(arr, n);
    long end2 = clock();
    cout << "Thoi gian thuc hien cua Insertion Sort la: " << end2 - start2 << " giay" << endl;
    cout << "So phep gan cua Insertion Sort la:" << n*n/4 << " phep" << endl;
    cout << "So phep so sanh cua Insertion Sort la:" << n*n/4 << " phep" << endl;
    long start3 = clock();
    heapSort(arr, n);
    long end3 = clock();
    cout << "Thoi gian thuc hien cua Heap Sort la: " << end3 - start3 << " giay" << endl;
    cout << "So phep gan cua Heap Sort la:" << 3*n*log2(n) << " phep" << endl;
    cout << "So phep so sanh cua Heap Sort la:" << 2*n*log2(n) << " phep" << endl;
    long start4 = clock();
    quickSort(arr, 0, n - 1);
    long end4 = clock();
    cout << "Thoi gian thuc hien cua Quick Sort la: " << end4 - start4 << " giay" << endl;
    cout << "So phep gan cua Quick Sort la:" << 2*n*log2(n) << " phep" << endl;
    cout << "So phep so sanh cua Quick Sort la:" << n*log2(n) << " phep" << endl;
    long start5 = clock();
    mergeSort(arr, 0, n - 1);
    long end5 = clock();
    cout << "Thoi gian thuc hien cua Merge Sort la: " << end5 - start5 << " giay" << endl;
    cout << "So phep gan cua Merge Sort la:" << 6*n*log2(n) << " phep" << endl;
    cout << "So phep so sanh cua Merge Sort la:" << 2*n*log2(n) << " phep" << endl;
    
    return 0;
}

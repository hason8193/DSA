#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include"HeapSort.h"
#include"InsertionSort.h"
#include"SelectionSort.h"

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
    int* arr_cpy = new int[n];
    const char* file = "random_numbers.txt";
    long long start = clock();
    Tao_Mang_Cho_File(file, arr, n);
    Doc_Mang_Tu_File(file, arr, n);
    long long begin_s = clock();
    for (int i = 0; i < n; i++) {
        arr_cpy[i] = arr[i];
    }
    Selection_Sort(arr_cpy, n);
    long long end_s = clock();
    cout << "Thoi gian thuc hien cua selection sort: " << end_s - begin_s << endl;
    long long begin_i = clock();
    for (int i = 0; i < n; i++) {
        arr_cpy[i] = arr[i];
    }
    Insertion_Sort(arr_cpy, n);
    long long end_i = clock();
    cout << "Thoi gian thuc hien cua insertion sort: " << end_i - begin_i << endl;
    long long begin_h = clock();
    for (int i = 0; i < n; i++) {
        arr_cpy[i] = arr[i];
    }
    heapSort(arr_cpy, n);
    long long end_h = clock();
    cout << "Thoi gian thuc hien cua heap sort: " << end_h - begin_h << endl;
    return 0;
}

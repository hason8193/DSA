#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include"HeapSort.h"

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
    long start = clock();
    Tao_Mang_Cho_File(file, arr, n);
    Doc_Mang_Tu_File(file, arr, n);
    heapSort(arr, n);
    cout << "Mang sau khi chinh sua la:" << endl;
    Xuat_Mang(arr, n);
    long end = clock();
    cout << "Thoi gian thuc hien: " << end - start << " giay";
    return 0;
}

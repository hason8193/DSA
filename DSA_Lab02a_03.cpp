#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,k=0;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n,greater<int>());
    for(int i = 0; i < n; i++){
        if(arr[i] >= i+1) k = i+1;
        else break;
    }
    cout << k;
}
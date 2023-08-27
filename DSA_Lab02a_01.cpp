#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        int c[n+m];
        merge(a, a+n, b, b+m, c); // trộn hai mảng a và b thành mảng c
        for (int i = 0; i < n+m; i++) {
            cout << c[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[i] - '0';
    }
    sort(s.rbegin(), s.rend());
    if (sum % 3 == 0) {
        cout << s << endl;
    } else if (sum % 3 == 1) {
        string s1 = "";
        bool removed = false;
        for (int i = n - 1; i >= 0; i--) {
            if ((s[i] - '0') % 3 == 1) {
                s.erase(i, 1);

            removed = true;
            break;
        }
    }
        if (!removed) {
            for (int i = n - 1; i >= 0; i--) {
                if ((s[i] - '0') % 3 == 2) {
                    s.erase(i, 1);
                    break;
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                s1 += s[i];
            }
            cout << s1 << endl;
        } else {
            for (int i = n - 1; i >= 0; i--) {
                s1 += s[i];
            }
            cout << s1 << endl;
        }
} else {
    string s1 = "";
    bool removed = false;
    for (int i = n - 1; i >= 0; i--) {
        if ((s[i] - '0') % 3 == 2) {
            s.erase(i, 1);
            removed = true;
            break;
        }
        }
        if (!removed) {
            for (int i = n - 1; i >= 0; i--) {
                if ((s[i] - '0') % 3 == 1) {
                    s.erase(i, 1);
                    break;
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                s1 += s[i];
            }
            cout << s1 << endl;
        } else {
            for (int i = n - 1; i >= 0; i--) {
                s1 += s[i];
            }
            cout << s1 << endl;
        }
    }
    return 0;
}

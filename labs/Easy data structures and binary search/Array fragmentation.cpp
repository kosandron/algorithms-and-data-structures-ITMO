#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (2*i + 1 < n && a[i] > a[2*i + 1]) {
            ans = false;
            break;
        }
        if (2*i + 2 < n && a[i] > a[2*i + 2]) {
            ans = false;
            break;
        }

    }
    if (ans) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}

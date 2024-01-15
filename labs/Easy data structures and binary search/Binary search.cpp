#include <bits/stdc++.h>
using namespace std;

int leftx(vector <int> &a, int n, int x) {
    int l = 0, r = n - 1;
    int res = -2;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) {
            res = m;
            r = m - 1;
        } else if (x < a[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return (res + 1);
}

int rightx(vector <int> &a, int n, int x) {
    int l = 0, r = n - 1;
    int res = -2;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) {
            res = m;
            l = m + 1;
        } else if (x < a[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return (res + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << leftx(a, n, x) << " " << rightx(a, n, x) << '\n';
    }

    return 0;
}

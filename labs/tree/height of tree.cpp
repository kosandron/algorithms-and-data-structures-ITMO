#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector <int> a(n, 0);
    int k, l, r;
    if (n == 0) {
        cout <<0;
        return 0;
    }
    a[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> k >> l >> r;
        if (l != 0)
            a[l - 1] = a[i] + 1;
        if (r != 0)
            a[r - 1] = a[i] + 1;

    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
    }
    cout<<mx;
    return 0;
}

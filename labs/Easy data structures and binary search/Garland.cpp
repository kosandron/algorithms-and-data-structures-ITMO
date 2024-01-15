#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector <double> h(n);
    cin >> h[0];
    double l = 0, r = 1e12;
    double ans = 1e12;
    while (r - l > 1e-6) {
        double m = (l + r) / 2;
        h[1] = m;
        bool sit = false;
        for (int i = 2; i < n; i++) {
            h[i] = 2 * (h[i - 1] + 1)  - h[i - 2];
            if (h[i] <= 0) {
                sit = true;
                break;
            }
        }
        if (h[1] <= 0)
            sit = true;
        if (sit) {
            l = m;
        } else {
            r = m;
            ans = min(ans, h[n - 1]);
        }
    }
    printf("%.2f", ans);

    return 0;
}

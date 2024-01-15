#include <bits/stdc++.h>
using namespace std;
int partition(vector<int32_t>& a, int left, int right) {
    int piv = a[left];
    int i = left - 1;
    int j = right + 1;

    while (true) {
        do {
            i++;
        } while (a[i] < piv);
        do {
            j--;
        } while (a[j] > piv);
        if (i >= j) {
            return j;
        }

        swap(a[i], a[j]);
    }
}

void quickSort(vector<int32_t>& a, int l, int r, int k) {
    if (l < r) {
        int q = partition(a, l, r);
        if (k <= q) {
            quickSort(a, l, q, k);
        }
        if (k > q) {
            quickSort(a, q + 1, r, k);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector <int32_t> a(n);
    int A, B, C;
    cin >> A >> B >> C >> a[0] >> a[1];
    for (int i = 2; i < n; i++) {
        a[i] = A * a[i-2] + B * a[i-1] + C;
    }

    quickSort(a, 0, n-1, k-1);

    cout<<a[k-1];
    return 0;
}

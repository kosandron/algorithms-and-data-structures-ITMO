#include <iostream>
using namespace std;
int Partition(int* a, int l, int r) {
    int v = a[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (a[i] < v) {
            i++;
        }
        while (a[j] > v) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(a[i++], a[j--]);
    }
    return j;
}
void QuickSort(int* a, int l, int r) {
    if (l < r) {
        int q = Partition(a, l, r);
        QuickSort(a, l, q);
        QuickSort(a, q + 1, r);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i< n; i++) {
        cin>>a[i];
    }

    QuickSort(a, 0, n-1);

    for (int i = 0; i < n;i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}

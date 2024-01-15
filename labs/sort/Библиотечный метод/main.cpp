#include <iostream>
using namespace std;
void Print(int n, int *a){
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<'\n';
}
void InsertionSort(int n, int *a) {
    for (int i = 1; i < n;i++) {
        int j = i - 1;
        bool was_swap = false;
        while (j >= 0 && a[j] > a[j+1]) {
            was_swap = true;
            swap(a[j], a[j+1]);
            j--;
        }
        if (was_swap)
            Print(n, a);
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
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    InsertionSort(n,a);
    return 0;
}

#include <iostream>
using namespace std;
struct Part {
  int begin;
  int end;
};

void MergeMas(Part* a, int left, int mid, int right) {
    int it1 = 0;
    int it2 = 0;
    Part result[right - left];

    while ((left + it1 < mid) && (mid + it2 < right)) {
        if (a[left + it1].begin  < a[mid + it2].begin or (a[left + it1].begin == a[mid + it2].begin && a[left + it1].end < a[mid + it2].end)) {
            result[it1 + it2] = a[left + it1];
            it1++;
        } else {
            result[it1 + it2] = a[mid + it2];
            it2++;
        }
    }
    while (left + it1 < mid) {
        result[it1 + it2] = a[left + it1];
        it1++;
    }

    while (mid + it2 < right) {
        result[it1 + it2] = a[mid + it2];
        it2++;
    }

    for (int i = 0; i < it1 + it2; i++){
        a[left + i] = result[i];
    }
}
void MergeSort(Part* a, int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    int mid = (left + right) / 2;
    MergeSort(a, left, mid);
    MergeSort(a, mid, right);
    MergeMas(a, left, mid, right);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    Part a[n];
    for (int i = 0; i < n; i++){
        cin>>a[i].begin>>a[i].end;
        if (a[i].begin > a[i].end) {
            swap(a[i].begin, a[i].end);
        }
    }

    MergeSort(a, 0, n);

    int point = -1;
    int ans = 0;
    for (int i = 0;i < n;i++){
        if (a[i].end < point) continue;
        bool new_desk = false;
        if (point < a[i].begin){
            point = a[i].begin;
            new_desk = true;
        }
        if (ans < a[i].end){
            ans += a[i].end - point;
            point = a[i].end;
        }
        if (new_desk) {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

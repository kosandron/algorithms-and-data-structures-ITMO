#include <iostream>
using namespace std;
struct User {
  int point;
  int number;
};

void MergeMas(User* a, int left, int mid, int right) {
    int it1 = 0;
    int it2 = 0;
    User result[right - left];

    while ((left + it1 < mid) && (mid + it2 < right)) {
        if (a[left + it1].point > a[mid + it2].point or (a[left + it1].point == a[mid + it2].point && a[left + it1].number < a[mid + it2].number)) {
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
void MergeSort(User* a, int left, int right) {
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
    User a[n];
    for (int i = 0; i < n; i++){
        cin>>a[i].number>>a[i].point;
    }

    MergeSort(a, 0, n);

    for (int i = 0; i < n; i++){
        cout<<a[i].number<<" "<<a[i].point<<'\n';
    }
    return 0;
}

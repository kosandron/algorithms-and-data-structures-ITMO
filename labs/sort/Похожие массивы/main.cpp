#include <iostream>
void MergeMas(int* a, int left, int mid, int right) {
    int it1 = 0;
    int it2 = 0;
    int result[right - left];

    while ((left + it1 < mid) && (mid + it2 < right)) {
        if (a[left + it1] < a[mid + it2]) {
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
void MergeSort(int* a, int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    int mid = (left + right) / 2;
    MergeSort(a, left, mid);
    MergeSort(a, mid, right);
    MergeMas(a, left, mid, right);
}
int main(){
    int n, k;
    std::cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin>>a[i];
    }
    std::cin>>k;
    int b[k];
    for (int i = 0; i < k; i++) {
        std::cin>>b[i];
    }
    MergeSort(a, 0, n);
    MergeSort(b, 0, k);

    bool ans = true;
    //  1 7 9 and 9 3 7 1
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (a[i] != b[j] && j != k){
            j++;
        }
        if (j == k) {
            ans = false;
        }
    }
    //םאמבמנמע
    j = 0;
    for (int i = 0; i < k; i++) {
        while (b[i] != a[j] && j != n){
            j++;
        }
        if (j == n) {
            ans = false;
        }
    }
    if (ans == true) {
        std::cout<<"YES";
    } else {
        std::cout<<"NO";
    }
    return 0;
}

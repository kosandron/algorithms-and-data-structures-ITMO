#include <bits/stdc++.h>
using namespace std;

int a_index = 0;

void print(vector<int>& a, int lg, int rg) {
    if (a[a_index] > rg or a[a_index] < lg or a_index >= a.size()) {
        return;
    }

    int parent_key = a[a_index];
    a_index++;
    print(a, lg, parent_key);
    print(a, parent_key, rg);
    cout << parent_key << " ";
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
    print(a, INT_MIN, INT_MAX);

    return 0;
}

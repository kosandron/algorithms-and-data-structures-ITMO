#include <bits/stdc++.h>
using namespace std;

void countingSort(string* a, int razrad, int n) {
    int c[26]; // двузначные неотрицательные
    for (int i = 0; i < 26; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        c[a[i][razrad] - 'a']++;
    }
    for (int i = 1; i < 26; i++) {
        c[i] = c[i] + c[i - 1];
    }
    string b[n];
    for (int i = n - 1; i >= 0; i--) {
        b[c[a[i][razrad] - 'a'] - 1] = a[i];
        c[a[i][razrad] - 'a']--;
    }
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;
    string a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k = 0;
    for (int i = m - 1; i >= 0; i--){
        countingSort(a, i, n);
        k++;
        if (k == s) break;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}

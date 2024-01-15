#include <bits/stdc++.h>
using namespace std;
vector <int> b;

int z = 1;
struct v {
    int left = 0;
    int right = 0;
    int key = INT_MIN;
};

void obhod(vector<v>& a, int x) {
    if (a[x].key != INT_MIN) {
        obhod(a, a[x].left);
        a[x].key = z;
        z++;
        obhod(a, a[x].right);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector <v> a(n + 1);

    //cout << 5;
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i].left >> a[i].right;
       a[i].key = 0;
    }

    obhod(a, 1);

    for (int i = 1; i < n + 1; i++) {
        cout << a[i].key << " ";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector <int> b;
struct v {
    int left = 0;
    int right = 0;
    int key = INT_MIN;
};

void obhod(vector<v>& a, int x) {
    if (a[x].key != INT_MIN) {
        obhod(a, a[x].left);
        b.push_back(a[x].key);
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
    if (n == 0) {
        cout <<"YES";
        return 0;
    }

    //cout << 5;
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i].key >> a[i].left >> a[i].right;
       /* if (a[i].left == 0) {
            a[i].key = INT_MIN;
        }
        if (a[i].right == 0) {
            a[i].key = INT_MIN;
        }*/
    }

    obhod(a, 1);

    bool ans = true;
    for (int i = 1; i < n; i++) {
        if (b[i] <= b[i - 1]) {
            ans = false;
            break;
        }
    }
    /*for (int i = 0; i < n; i++) {
        cout <<b[i] <<" ";
    }*/
    if(ans == true) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}

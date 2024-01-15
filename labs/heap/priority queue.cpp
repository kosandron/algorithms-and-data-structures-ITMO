#include <iostream>
#include <vector>

#define ll long long
#define ld long double

using namespace std;

struct point {
  int value;
  int t;
};

struct Node {
    int value;
    int index;
};

 vector <point> h;
 vector <Node> points;
 int n = 0;

int insert(int value, int ts){
     point new_value;
     new_value.value = value;
     new_value.t = ts;
     h.push_back(new_value);
     n++;

     int i = n-1;
     while (i > 0 && h[i].value < h[(i-1)/2].value){
         swap(h[i], h[(i-1)/2]);
         i = (i - 1) / 2;
     }
     return i;
 }

 int remove_min(){
     int res = h[0].value;
     h[0] = h[n-1];
     h.pop_back();
     n--;

     int i = 0;
     int j = i;

     while (true){
         int m = h[i]. value;
         int ts = h[i].t;
         if (2 * i + 1 < n && (h[2*i + 1].value < m or (h[2*i + 1].value == m && h[2*i + 1].t < ts))){
             j = 2 * i + 1;
             m = h[2 * i + 1].value;
             ts = h[2 * i + 1].t;
         }
         if(2 * i + 2 < n && (h[2 * i + 2].value < m or (h[2*i + 2].value == m && h[2*i + 2].t < ts))){
             j = 2 * i + 2;
             m = h[2 * i + 2].value;
             ts = h[2 * i + 2].t;
         }
         if (i == j)
            break;
         swap(h[i], h[j]);
         i = j;
     }

     return res;
 }


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s = "";
    int x, y;
    int k = 1;
    vector <int> str;
    while (cin >> s) {
        if (s == "push"){
            cin >> x;
            str.push_back(n);
            Node r;
            r.value = x;
            r.index = insert(x, k);
            k++;
        } else if (s == "extract-min") {
            if (n == 0){
                cout << '*' << '\n';
            } else {
                cout << remove_min()<< '\n';
            }
            k++;
        } else if (s == "decrease-key") {

            cin >> x >> y;
            int z;
            for (int i = 0; i < n; i++) {
                if (h[i].t == x){
                    z = i;
                    break;
                }
            }
            h[z].value = y;

            int i = z;
            while (i > 0 && (h[i].value < h[(i-1)/2].value or ( h[i].value == h[(i-1)/2].value && h[i].t < h[(i-1)/2].t) ) ) {
                 swap(h[i], h[(i-1)/2]);
                 i = (i - 1) / 2;
            }
            k++;
        }

    }
    return 0;
}

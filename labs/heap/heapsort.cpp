#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
 vector <int> a;
 int n = 0;
 void hinsert(int x){
     a.push_back(x);
     n++;
     int i = n-1;
     while (i> 0 && a[i]>a[(i-1)/2]){
         swap(a[i], a[(i-1)/2]);
         i = (i-1)/2;
     }
 }
 int remove_max(){
     int res = a[0];
     a[0]=a[n-1];
     a.pop_back();
     n--;
     int i = 0;
     int j = i;
     while (true){
         int m = a[i];
         if (2*i + 1 <n && a[2*i+1]>m){
             j = 2*i + 1;
             m= a[2*i+1];
         }
         if (2*i + 2 <n && a[2*i+2]>m){
             j = 2*i + 2;
             m= a[2*i+2];
         }
         if (i == j)
            break;
         swap(a[i], a[j]);
         i = j;
     }
     return res;
 }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    n = 0;

    int t;
    cin>>t;
    vector <int> b(t);
    for (int i = 0;i< t;i++){
        cin>>b[i];
        hinsert(b[i]);
    }
    for (int i = 0;i< t;i++){
        b[i] = remove_max();
    }
    for (int i = t-1;i>=0;i--){
        cout<<b[i]<<" ";
    }
    return 0;
}

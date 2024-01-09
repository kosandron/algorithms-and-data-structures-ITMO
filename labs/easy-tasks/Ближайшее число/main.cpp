#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0;i<n;i++){
        scanf("%d", &a[i]);
    }
    int s = 0;
    scanf("%d", &s);
    int diff = 10000000;
    int ans;
    for (int i = 0;i<n;i++){
        if (abs(s-a[i])< diff){
            diff = abs(s-a[i]);
            ans = a[i];
        }
    }
    printf("%d", ans);
    return 0;
}

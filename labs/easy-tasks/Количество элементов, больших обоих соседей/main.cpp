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
    int k = 0;
    for (int i = 1;i<n-1;i++){
        if (a[i]>a[i-1] && a[i]> a[i+1]){
            k++;
        }
    }
    printf("%d", k);
    return 0;
}

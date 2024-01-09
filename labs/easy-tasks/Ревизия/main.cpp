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
    int m1, m1_ind, m2;
    m1 = INT_MAX;
    m2 = m1;
    for (int i = 0;i<n;i++){
        if (a[i] < m1){
            m1 = a[i];
            m1_ind = i;
        }
    }
    for (int i = 0;i<n;i++){
        if (m2 > a[i] && i != m1_ind){
            m2 = a[i];
        }
    }
    printf("%d %d", m1, m2);
    return 0;
}

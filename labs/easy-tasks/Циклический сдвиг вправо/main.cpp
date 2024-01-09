#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0;i<n;i++){
        scanf("%d", &a[i]);
    }
    int c = a[n-1];
    for (int i = n-1;i>0;i--){
        a[i] = a[i-1];
    }
    a[0] = c;
    for (int i = 0;i<n;i++){
        printf("%d ", a[i]);
    }
    return 0;
}

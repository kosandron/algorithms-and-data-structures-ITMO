#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n+1];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int enter, place;
    cin>>enter>>place;
    a[n] = enter;
    for (int i = n;i > place-1;i--){
        swap(a[i], a[i-1]);
    }

    for (int i = 0; i < n+1; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}

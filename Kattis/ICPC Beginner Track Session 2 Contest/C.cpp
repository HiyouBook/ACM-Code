#include<iostream>

using namespace std;
const int N = 1e6 + 10;

int p[N], a[N], b[N];

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    a[1] = p[1];
    for(int i = 2; i <= n; i++)
        a[i] = max(p[i], a[i - 1]);
    b[n] = p[n];
    for(int i = n - 1; i >= 1; i--)
        b[i] = min(p[i], b[i + 1]);
    for(int i = 1; i <= n; i++)
        if(p[i] == a[i] && p[i] == b[i])
            ans++;
    cout << ans << endl;
    return 0;
}


/* 
https://open.kattis.com/contests/up3ds7/problems/pivot
 */
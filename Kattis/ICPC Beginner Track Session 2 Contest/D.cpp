#include<iostream>

using namespace std;
const int N = 1e6 + 10;
typedef long long ll;

ll p[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    ll a, b, ans;
    a = b = ans = 0;
    for(int i = 1; i <= n; i++)
        b += p[i];
    for(int k = 1; k < n; k++){
        a += p[k] * p[k];
        b -=  p[k];
        ans = max(ans, a * b);
    }
    cout << ans << endl;
    return 0;
}
/* 
https://open.kattis.com/contests/up3ds7/problems/inquiryi
 */
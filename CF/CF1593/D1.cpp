#include <iostream>

using namespace std;

const int N = 100;

int a[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, min_a;
        cin >> n;
        min_a = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (min_a > a[i])
                min_a = a[i];
        }
        for (int i = 1; i <= n; i++)
            a[i] -= min_a;
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i]) {
                if (~ans)
                    ans = gcd(ans, a[i]);
                else
                    ans = a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
 * @Contest: Codeforces Round #748 (Div. 3)
 * @Problems: D1. All are Same
 * @Author: Hiyou
 * @Date: 2021-10-14 16:22:16
 */

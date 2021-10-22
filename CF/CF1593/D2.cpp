#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int N = 2e6 + 10;
const int M = 1e6 + 1;

int cnt[N], a[50], b[50], c[N], d[N], idx, n, m;
int ans;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof cnt);
        int n;
        cin >> n;
        idx = m = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i], a[i] += M;
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) {
            if (!cnt[a[i]])
                b[++idx] = a[i];
            cnt[a[i]]++;
        }
        bool flag = false;
        for (int i = 1; i <= idx; i++)
            if (cnt[b[i]] * 2 >= n)
                flag = true;
        if (flag) {
            cout << "-1" << endl;
            continue;
        }
        for (int i = 1; i <= idx; i++) {
            for (int j = 1; j < i; j++) {
                int u = b[i] - b[j];
                int x = sqrt(u);
                for (int k = 1; k <= x; k++) {
                    if (!(u % k) && !d[k]) 
                        c[++m] = k, d[k]++;   
                    if(!(u % k) && (!d[u / k]))
                        c[++m] = u / k, d[u / k]++;
                }
            }
        }
        memset(d, 0, sizeof d);
        sort(c + 1, c + 1 + m, greater<>());
        int k;
        for (k = 1; k <= m; k++) {
            for (int i = 1; i <= idx; i++) {
                int u = b[i] % c[k];
                d[u] += cnt[b[i]];
            }
            for (int i = 1; i <= idx; i++) {
                int u = b[i] % c[k];
                if (d[u] * 2 >= n)
                    flag = true;
                d[u] = 0;
            }
            if (flag)
                break;
        }
        cout << c[k] << endl;
    }
}

/*
 * @Contest: Codeforces Round #748 (Div. 3)
 * @Problems: https://codeforces.com/contest/1593/problem/D2
 * @Author: Hiyou
 * @Date: 2021-10-15 09:14:41
 */

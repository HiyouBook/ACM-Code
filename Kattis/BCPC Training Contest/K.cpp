#include <cstring>
#include <iostream>

using namespace std;
const int N = 1e5 + 10;

int f[N], v[N], num[N], idx;

void init() {
    for (int i = 2; i < N; i++) {
        if (!v[i])
            f[++idx] = v[i] = i;
        for (int j = 1; j <= idx && f[j] <= v[i] && f[j] * i < N; j++)
            v[i * f[j]] = f[j];
    }
}

bool check(int x) {
    memset(f, 0, sizeof f);
    bool flag = true;
    while(x != 1){
        int u = 0;
        if(f[x]){
            // cout << x << endl;
            flag = false;
            break;
        }
        f[x] = 1;
        while(x){
            u += (x % 10) * (x % 10);
            x /= 10;
        }
        x = u;
    }
    return flag;
}

int main() {
    init();
    memset(f, 0, sizeof f);
    int n;
    cin >> n;
    while (n--) {
        int k, x;
        cin >> k >> x;
        cout << k << " " << x << " ";
        if (v[x] == x && check(x))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

/*
https://open.kattis.com/contests/xcewjg/problems/happyprime
 */
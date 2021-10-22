#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> PII;

const int N = 4e5 + 10;
vector<int> q[N];
int f[N];

void init(int n) {
    for (int i = 0; i <= n; i++)
        q[i].clear(), f[i] = 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        init(n);
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            q[a].push_back(b);
            q[b].push_back(a);
            f[a]++;
            f[b]++;
        }
        if(n == 1){
            if(!k)
                cout << 1 << endl;
            else cout << 0 << endl;
            continue;
        }
        queue<PII> qq;
        for (int i = 1; i <= n; i++)
            if (f[i] == 1)
                qq.push({i, 1});
        int ans = n;
        while (!qq.empty()) {
            auto x = qq.front();
            qq.pop();
            int u = x.first, p = x.second;
            if (p > k)
                break;
            ans--;
            for (auto i = q[u].begin(); i != q[u].end(); i++) {
                if (--f[*i] == 1)
                    qq.push({*i, p + 1});
            }
        }
        cout << ans << endl;
    }
    return 0;
}
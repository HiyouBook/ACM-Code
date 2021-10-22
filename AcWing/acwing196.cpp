#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
const ll M = 0xffffffff - 1 ;

ll f[N], v[N], p[N], num[N], idx;

void init(){
    for(int i = 2; i <= sqrt(M); i++){
        if(!v[i]) f[++idx] = v[i] = i;
        for(int j = 1; j <= idx; j++){
            if(f[j] > v[i] || i * f[j] > sqrt(M)) break;
            v[i * f[j]] = f[j];
        }
    }
}

int main(){
    ll l, r;
    init();
    while(~scanf("%lld%lld", &l, &r)){
        memset(num, 0, sizeof num);
        int id = 0;
        for(int i = 1; i <= idx; i++){
            int u = max(l / f[i] + (l % f[i] != 0), 2ll);
            for(ll j = f[i] * u; j <= r; j += f[i])
                num[j - l]++;
        }
        for(ll i = max(l, 2ll); i <= r; i++){
            if(!num[i - l])
                p[++id] = i;
        }
        if(id < 2)
            puts("There are no adjacent primes.");
        else{
            int a, b, c, d;
            int x, y;
            x = 10000001, y = 0;
            for(int i = 1; i < id; i++){
                if(p[i + 1] - p[i] > y)
                    c = p[i], d = p[i + 1], y = d - c;
                if(p[i + 1] - p[i] < x)
                    a = p[i], b = p[i + 1], x = b - a;
            }
            printf("%d,%d are closest, %d,%d are most distant.\n", a, b, c, d);
        }        
    }
    return 0;
}
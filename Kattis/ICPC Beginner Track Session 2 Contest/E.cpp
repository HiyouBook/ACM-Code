#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1e5 + 10;

int f[50];
struct no{
    int a;
    int b;
}p[N];

bool cmp(no x, no y){
    return x.a > y.a;
}


int main(){
    int n, t;
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
        cin >> p[i].a >> p[i].b;
    sort(p + 1, p + 1 + n, cmp);
    for(int i = 1; i <= n; i++){
        int j;
        for(j = p[i].b; j >= 0 && f[j]; j--);
        if(j != -1)
            f[j] = p[i].a;
    }
    int ans = 0;
    for(int i = 0; i < t; i++)
        ans += f[i];
    cout << ans << endl;
    return 0;
}

/* 
https://open.kattis.com/contests/up3ds7/problems/bank
 */
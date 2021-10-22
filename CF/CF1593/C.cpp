#include<iostream>
#include<algorithm>

using namespace std;
const int N = 4e5 + 10;
typedef long long ll;

int a[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= k; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + k, greater<>() );
        ll ans = 0;
        int flag = k;
        for(int i = 1; i <= k ; i++){
            ans += n - a[i];
            if(ans >= n){
                flag = i - 1;
                break;
            }
        }
        cout << flag << endl;
    }
    return 0;
}


/*
 * @Contest: Codeforces Round #748 (Div. 3)
 * @Problems: C. Save More Mice
 * @Author: Hiyou
 * @Date: 2021-10-14 15:05:07
 */

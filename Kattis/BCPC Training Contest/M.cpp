#include<iostream>

using namespace std;

bool check(int n){
    if(!n)
        return false;
    int m = n, ans = 0;
    while(m){
        ans += m % 10;
        m /= 10;
    }
    return n % ans;
}

int main(){
    int n, i;
    cin >> n;
    i = n;
    while(check(i))
        i++;
    cout << i << endl;
    return 0;
}

/* 
https://open.kattis.com/contests/xcewjg/problems/harshadnumbers
 */
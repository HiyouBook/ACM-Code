#include<iostream>

using namespace std;
int p[100], f[100];

void dfs(int u, int ans, int id){
    if(id > 7){
        if(ans == 100)
            for(int i = 1; i <= 7; i++)
                cout << f[i] << endl;
        return;
    }
    for(int i = u; i <= 9; i++){
        if(ans + p[i] <= 100){
            f[id] = p[i];
            dfs(i + 1, ans + p[i], id + 1);
        }
    }
    
}

int main(){
    for(int i = 1; i <= 9; i++)
        cin >> p[i];
    dfs(1, 0, 1);
    return 0;
}

/* 
https://open.kattis.com/contests/xcewjg/problems/patuljci
 */
#include<iostream>
#include<map>

using namespace std;

int main(){
    map<string, int> q;
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        cout << q[s] << endl;
        string line;
        for(int i = 0; i < s.size(); i++){
            line += s[i];
            q[line]++;
        }
    }
    return 0;
}


/* 
https://open.kattis.com/contests/xcewjg/problems/bing
 */
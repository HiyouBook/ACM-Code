#include<iostream>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    int x = 0;
    bool flag = true;
    for(int i = 0; i < b.size(); i++){
        if(a[x] == b[i])
            x++;
        else
            for(int j = x; j < a.size(); j++){
                if(a[j] == b[i])
                    flag = false;
            }
        if(!flag)
            break;
    }
    if(flag && x == a.size())
        cout << "PASS" << endl;
    else cout << "FAIL" << endl;
    return 0;
}


/* 
https://open.kattis.com/contests/up3ds7/problems/hidden
 */
#include<iostream>
#include<cstring>
#include<sstream>

using namespace std;

int a[100];

int main(){
    string ss;
    getline(cin, ss);
    stringstream line(ss);
    int n;
    line >> n;
    while(n--){
        memset(a, 0, sizeof a);        
        string s;
        getline(cin, s);
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z')
                a[s[i] - 32]++;
            else if(s[i] >= 'A' && s[i] <= 'Z')
                a[s[i]]++;
        }
        bool flag = true;
        for(int i = 'A'; i <= 'Z'; i++)
            if(!a[i])
                flag = false;
        if(flag)
            cout << "pangram" << endl;
        else{
             cout << "missing ";
             for(int i = 'A'; i <= 'Z'; i++)
                if(!a[i])
                    cout << (char)(i + 32);
            cout << endl;
        }
        
    }
    return 0;
}

/* 
https://open.kattis.com/contests/up3ds7/problems/quickbrownfox
 */
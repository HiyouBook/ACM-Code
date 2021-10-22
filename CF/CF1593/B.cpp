#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int a, b, c, d, o;
        a = b = c = d = 0x3f3f3f3f;
        o = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if ((s[i] == '2' || s[i] == '7') && a != 0x3f3f3f3f &&
                c == 0x3f3f3f3f)
                c = i;
            if ((s[i] == '0' || s[i] == '5') && b != 0x3f3f3f3f &&
                d == 0x3f3f3f3f)
                d = i;
            if (s[i] == '5' && a == 0x3f3f3f3f)
                a = i;
            if (s[i] == '0' && b == 0x3f3f3f3f)
                b = i;

            if (s[i] != '0')
                o++;
        }
        if (c == 0x3f3f3f3f && d == 0x3f3f3f3f)
            cout << o << endl;
        else {
            int n = s.size();
            // cout << n << " " << d << " " << c << endl;
            if (d != 0x3f3f3f3f && c != 0x3f3f3f3f)
                cout << min(n - d - 2, n - c - 2) << endl;
            else if (d != 0x3f3f3f3f)
                cout << n - d - 2 << endl;
            else
                cout << n - c - 2 << endl;
        }
    }
    return 0;
}

/*
 * @Contest: Codeforces Round #748 (Div. 3)
 * @Problems: B. Make it Divisible by 25
 * @Author: Hiyou
 * @Date: 2021-10-14 15:04:52
 */

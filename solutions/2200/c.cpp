#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; string s;
    cin >> n >> s;
    for(int i = 1; i<n; i++) {
        for(int j = i-1; j>=0; j--) {
            if(s[j] == '*') continue;
            if(s[i] == s[j]) {
                s[i] = s[j] = '*';
            } else break;
        }
    }
    // for(int l = 2; l<=n; l+=2) {
    //     for(int i = 0; i<n; i++) {
    //         int j = i + l - 1;
    //         if(j >= n || s[i] == '*' || s[j] == '*') continue;
    //         if(s[i] == s[j]) {
    //             for(int k = i + 1; k<j; k++)
    //                 if(s[k] != '*') return void(cout << "NO\n");
    //             s[i] = s[j] = '*';
    //         }
    //     }
    // }
    for(char c: s) if(c != '*')return void(cout << "NO\n");
    cout << "YES\n";
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

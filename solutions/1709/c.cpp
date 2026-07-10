#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int cur = 0, q = 0;
    vector<int> pref;
    for(char c: s) {
        if(c == '(') cur++;
        else if(c == ')') cur--;
        else q++;
    }
    int st = (q - cur) / 2;
    int en = q - st;
    if(!st || !en) return void(cout << "YES\n");

    int cnt = 0;
    int lso = 0, frc = -1;
    for(int i = 0; i<s.size(); i++) if(s[i] == '?') {
        if(cnt < st) s[i] = '(', cnt++, lso = i;
        else {
            s[i] = ')';
            if(frc == -1) frc = i;
        }
    }
    cur = 0;
    for(char c: s) {
        if(c == '(') cur++;
        else cur--;
        pref.push_back(cur);
    }
    for(int i = lso; i<frc; i++) if(pref[i] < 2) return void(cout << "YES\n");
    cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

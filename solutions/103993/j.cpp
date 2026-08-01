#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    string s; cin >> s;
    reverse(s.begin(), s.end());
    while(s.size() && s.back() == '0') s.pop_back();
    n = s.size();
    if(n == 0) {
        cout << 0 << '\n';
        return;
    }
    reverse(s.begin(), s.end());
    bool fz = false;
    vector<int> cands;
    int fi = 0;
    for(int i = 0; i<n; i++) {
        if(s[i] == '1') {
            if(!fz) cands.push_back(i);
            continue;
        }
        if(!fz) fi = i;
        fz = true;
        vector<int> nc;
        int cnt = 0;
        for(int c: cands) if(s[c+i-fi] == '1') cnt++;
        if(cnt) {
            for(int c: cands) if(s[c+i-fi] == '1') nc.push_back(c);
        } else continue;
        swap(cands, nc);
    }
    int best = cands[0];
    int len = n - fi;
    string nb = s;
    for(int x = best, j = n-len; j < n; x++, j++) {
        nb[j] = ((s[j]-'0') | (s[x]-'0'))+'0';
    }
    bool z = true;
    for(int i = 0; i < n; i++) {
        if(nb[i] == '0' && z) continue;
        else if(nb[i] == '1') z = false;
        if(!z) cout << nb[i];
    }
    if(z) cout << 0;
    cout << '\n';
}

void solven2(int n) {
    string s; cin >> s;
    string best = s;
    for(int i = 0; i < n; i++) {
        int len = i+1;
        string nb = s;
        for(int x = 0, j = n-len; j < n; x++, j++) {
            nb[j] = ((s[j]-'0') | (s[x]-'0'))+'0';
        }
        best = max(best, nb);
    }
    bool z = true;
    for(int i = 0; i < n; i++) {
        if(best[i] == '0' && z) continue;
        else if(best[i] == '1') z = false;
        if(!z) cout << best[i];
    }
    if(z) cout << 0;
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if(n <= 1000) solven2(n);
    else solve(n);
}

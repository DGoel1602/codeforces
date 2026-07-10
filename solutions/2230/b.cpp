#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    string s; cin >> s;
    int res = 0;
    int n = s.size();
    int fours = 0, twos = 0;

    for(int i = 0; i<n; i++) {
        if(s[i] == '4') fours++;
    }
    
    vector<pii> gs;
    pii g = {0, 0};
    for(int i = 0; i<n; i++) {
        if(s[i] == '1' || s[i] == '3') {
            if(g.second) {
                gs.push_back(g);
                g = {0, 0};
            }
            g.first++;        
        } else if(s[i] == '2' && g.first) g.second++;
    }
    if(g.second) gs.push_back(g);

    n = gs.size();
    vi pref(n+1, 0);
    rep(i, 1, n+1) pref[i] = pref[i-1] + gs[i-1].first;
    
    vi dp(n+1, 0);
    rep(i, 1, n+1) {
        dp[i] = min(pref[i], gs[i-1].second + dp[i-1]);
    }

    res = fours + dp[n];
    cout << res << '\n';
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

// 11
// 12 - 1
// 13
// 14
// 21
// 22
// 23
// 24 - 1
// 31
// 32 - 1
// 33
// 34
// 41
// 42
// 43
// 44 - 1

// 4 -> 2 -> 1, 2 -> 3, 4 -> 4

#include <bits/stdc++.h>
using namespace std;

#define int long long

const long long mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    vector<vector<vector<int>>> dp(n+5, vector<vector<int>>(n+5, vector<int>(n+5, -1)));
    auto go = [&](int i, int mx, int mx2, auto&& go)  -> int {
        if(i == n) return 1;
        auto &ref = dp[i][mx][mx2];
        if(ref != -1) return ref;
        ref = go(i+1, mx, mx2, go);
        if(a[i] >= mx2)
            ref = (ref + go(i+1, max(a[i], mx), (a[i] < mx) ? a[i] : mx2, go)) % mod;
        return ref;
    };
    cout << go(0, 0, 0, go) << '\n';
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

// 2 4 3 7 6

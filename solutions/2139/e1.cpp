#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for(int i = 1; i<n; i++) {
        int p; cin >> p;
        --p;
        adj[p].push_back(i);
    }

    vector<int> siz(n+1);
    int sl = 1e9;
    auto dfs = [&](int u, int d, auto&& dfs) -> void {
        siz[d]++;
        for(int v: adj[u]) dfs(v, d+1, dfs);
        if(!adj[u].size()) sl = min(sl, d);
    };
    dfs(0, 0, dfs);

    vector<int> pref(n+1, 0);
    pref[0] = siz[0];
    for(int i = 1; i<=sl; i++) pref[i] = pref[i-1] + siz[i];

    vector<int> dp(n+1, 0), dp2(n+1, 0);
    dp[k] = 1;
    int be = 0;
    for(int i = 0; i<=sl; i++) {
        for(int j = 0; j <= k; j++) dp2[j] = 0;
        for(int j = 0; j <= k; j++) if(dp[j]) {
            if(j >= siz[i]) dp2[j-siz[i]] = 1, be = i+1;
            int oused = k - j;
            int tot = pref[i];
            int zused = tot - oused;
            if(zused <= (n-k)) dp2[j] = 1, be = i+1;
        }
        swap(dp, dp2);
    }
    cout << be << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}

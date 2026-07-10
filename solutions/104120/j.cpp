#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<vector<int>> adj(n);

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<ll>> dp(n, vector<ll>(2, -1));
    auto go = [&](int u, int fr, int p, auto&& go) -> ll {
        if(dp[u][p] != -1) return dp[u][p];

        vector<pair<ll, ll>> ch;
        for(int v : adj[u]) {
            if(v == fr) continue;
            ch.push_back({go(v, u, 0, go), go(v, u, 1, go)});
        }

        sort(ch.begin(), ch.end(), [&](pair<ll, ll> &a, pair<ll, ll> &b) -> bool { return a.second - a.first < b.second - b.first;});
        
        vector<ll> pref(ch.size()+1, 0), suff(ch.size()+1, 0);
        for(int i = 0; i < ch.size(); i++) pref[i+1] = pref[i] + ch[i].first;
        for(int i = ch.size()-1; i >= 0; i--) suff[i] = suff[i+1] + ch[i].second;

        for(int i = 0; i <= ch.size(); i++) {
            dp[u][p] = max(dp[u][p], pref[i] + suff[i] + b[i+p]);
        }
        return dp[u][p];
    };
    go(0, -1, 0, go);

    cout << dp[0][0] << '\n';
}

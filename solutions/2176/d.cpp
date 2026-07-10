#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

vi a; vector<map<int, vector<int>>> adj;
const ll mod = 998244353;
map<pii, int> dp;

int go(int u, int c) {
    if(dp.count({u,c})) return dp[{u, c}];
    ll res = 1;
    for(int v: adj[u][c + a[u]]) {
        res = (res + go(v, a[u])) % mod;
    }
    return dp[{u, c}] = res;
}

void solve() {
    int n, m; cin >> n >> m;
    a.clear(); a.resize(n); 
    adj.clear(); adj.resize(n);
    dp.clear();
    for(int &x: a) cin >> x;
    for(int i = 0; i<m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u][a[v]].push_back(v);
    }
    ll ans = 0;
    for(int i = 0; i<n; i++) {
        for(auto [c, vec]: adj[i]) {
            for(int v: vec) ans = (ans + go(v, a[i])) % mod;
        }
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

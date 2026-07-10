#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    vvi adj(n);
    rep(i, 0, n-1) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi siz(n), cost(n);

    auto dfs1 = [&](int u, int p, auto&& dfs1) -> int {
        siz[u] = 1;
        for(int v: adj[u]) if(v != p) siz[u] += dfs1(v, u, dfs1);
        for(int v: adj[u]) if(v != p) cost[u] += siz[v] * (a[v] ^ a[u]) + cost[v];
        return siz[u];
    };

    dfs1(0,-1,dfs1);

    vi res(cost);
    auto dfs2 = [&](int u, int p, auto&& dfs2) -> void {
        int wmec = cost[p] - (siz[u] * (a[u] ^ a[p]) + cost[u]); 
        int wmes = siz[p] - siz[u];

        cost[u] += wmes * (a[u] ^ a[p]) + wmec;
        siz[u] += wmes;
        
        res[u] = cost[u];

        for(int v: adj[u]) if(v != p) dfs2(v, u, dfs2);
    };
    for(int v: adj[0]) dfs2(v, 0, dfs2);

    for(int x: res) cout << x << " ";
    cout << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

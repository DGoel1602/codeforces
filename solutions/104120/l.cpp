#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    --x;
    vector<vector<int>> adj(n);
    for(int i =0 ; i<n-1; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> sz(n, 1);
    vector<int> par(n);
    vector<int> depth(n);
    auto dfs = [&](int u, int p, int d, auto&& dfs) -> int {
        par[u] = p;
        depth[u] = d;
        for(int v: adj[u]) if(v != p) sz[u] += dfs(v, u, d+1, dfs);
        return sz[u];
    };
    dfs(0, -1, 0, dfs);

    cout << ((n - 1) - (sz[par[x]] - 1)) * 2 - depth[par[x]] + 1 << '\n';
}

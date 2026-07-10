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
    int n; cin >> n;
    vvi adj(n);
    rep(i, 0, n-1) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<multiset<int>> heights(n);
    vector<int> hs(n, 0);
    auto dfs1 = [&](int u, int p, auto&& dfs1) -> int {
        for(int v: adj[u]) if(v != p) heights[u].insert(dfs1(v, u, dfs1));
        if(heights[u].size()) hs[u] = *prev(heights[u].end()) + 1;
        return hs[u];
    };
    dfs1(0, -1, dfs1);

    vi outs(n+1);
    outs[hs[0] + 1]++;

    auto dfs2 = [&](int u, int p, auto&& dfs2) -> void {
        int parma = hs[p];
        if(parma == hs[u] + 1) {
            if(heights[p].size() > 1) parma = *prev(prev(heights[p].end())) + 1;
            else parma = 0;
        }
        heights[u].insert(parma);
        if(heights[u].size()) hs[u] = *prev(heights[u].end()) + 1;
        outs[hs[u] + 1]++;
        for(int v: adj[u]) if(v != p) dfs2(v, u, dfs2);
    };

    for(int u: adj[0]) dfs2(u, 0, dfs2);

    int comps = 1;
    for(int k = 1; k<=n; k++) {
        comps += outs[k];
        cout << min(comps, n) << " ";
    }
    cout << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; t = 1;
    while(t--) solve();
}

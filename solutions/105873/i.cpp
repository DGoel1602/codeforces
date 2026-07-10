#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    vector<vector<int>> adj(n);
    for(int i = 0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<pair<int, int>>> queries(n);
    vector<int> res(q);
    for(int i = 0; i<q; i++) {
        int u, k; cin >> u >> k;
        --u;
        queries[u].push_back({k, i});
    }

    auto dfs = [&](int u, int p, auto&& dfs) -> map<int, int> {
        map<int, int> cur;
        cur.insert({a[u], 1});
        for(int v: adj[u]) if(v != p) {
            map<int, int> ch = dfs(v, u, dfs);
            if(ch.size() > cur.size()) swap(ch, cur);
            for(auto [k, siz]: ch) cur[k] += siz;
        }
        for(auto [k, idx]: queries[u]) {
            res[idx] = cur[k];
        }
        return cur;
    };
    dfs(0, -1, dfs);
    for(int x: res) cout << x << "\n";
}

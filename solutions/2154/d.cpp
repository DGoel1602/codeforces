#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n);
    vector<int> path;
    vector<pair<int, int>> al;
    bool f = false;
    auto dfs = [&](int u, int p, int h, auto&& dfs) -> void {
        dist[u] = h;
        al.push_back({h, u});
        
        if(!f) path.push_back(u);
        if(u == n-1) f = true;

        for(int v: adj[u]) if(v != p) dfs(v, u, h+1, dfs);

        if(!f) path.pop_back();
    };

    dfs(0, -1, 0, dfs);
    sort(al.begin(), al.end(), greater<>());
    set<int> ps;
    for(int u: path) ps.insert(u), al.push_back({dist[u], u});

    int c = 0;
    vector<string> res;
    set<int> sp;
    for(auto [dis, u]: al) {
        if(ps.count(u) && !sp.count(u)) {
            sp.insert(u);
            continue;
        }
        if(dis % 2 == c % 2) res.push_back("1"), c++;
        else res.push_back("1"), res.push_back("1"), c += 2;
        if(u != n - 1) res.push_back("2 " + to_string(u+1));
        sp.insert(u);
    }
    cout << res.size() << "\n";
    for(string x: res) cout << x << "\n";
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

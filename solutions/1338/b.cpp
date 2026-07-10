#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i<n-1; i++) {
        int u, v; cin >> u >> v; 
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root = 0;
    while(adj[root].size() == 1) root++;

    set<int> poss;
    auto dfs = [&](int u, int p, int d, auto&& dfs) -> void {
        if(adj[u].size() == 1) poss.insert(d % 2);
        for(int v: adj[u]) if(v != p) dfs(v, u, d+1, dfs);
    };

    dfs(root, -1, 0, dfs);
    int mi = poss.size() == 1 ? 1 : 3;
    int ma = n - 1;
    for(int i = 0; i<n; i++) {
        int leaves = 0;
        for(int v: adj[i]) if(adj[v].size() == 1) leaves++;
        if(leaves) ma -= leaves - 1;
    }
    cout << mi << " " << ma << "\n";
}

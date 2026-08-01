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
    vector<char> res(n);
    auto dfs = [&](int u, int p, int d, auto&& dfs) -> void {
        res[u] = (d % 2) ? ')' : '(';
        for(int v: adj[u]) if(v != p) dfs(v, u, d+1, dfs);
    };
    dfs(0, -1, 0, dfs);
    for(char c: res) cout << c;
    cout << '\n';
}

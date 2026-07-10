#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int u, ll sp, ll jmp, vector<vector<int>> &adj, vector<int> &res) {
    int ch = adj[u].size();
    if(ch == 0) {
        for(ll i = sp; i < (ll)(res.size()); i += jmp) res[i] = u;
        return;
    }
    for(int i = 0; i < adj[u].size(); i++) {
        solve(adj[u][i], sp + min(1000000000LL, jmp*i), min(1000000000LL, jmp*ch), adj, res);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    for(int i = 1; i < n; i++) {
        int p; cin >> p;
        adj[p].push_back(i);
    }
    vector<int> res(q);
    solve(0, 0, 1, adj, res);

    for(int x : res) cout << x << '\n';
}

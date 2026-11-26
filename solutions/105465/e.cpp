#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)(a).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<array<int, 2>> dp(n, {-1, -1});
    auto dfs = [&](int u, int p, auto par, auto &&dfs) -> int {
        if(sz(adj[u]) == 1 && par != -1) return 2*(1-p);
        if(dp[u][p] != -1) return dp[u][p];

        vector<int> a, b;
        for(int v : adj[u]) {
            if(v == par) continue;
            a.push_back(dfs(v, 0, u, dfs));
            if(p == 0) b.push_back(dfs(v, 1, u, dfs));
        }
        
        int asum = 0, bsum = 0, md = 1e9;
        for(int x : a) asum += x;
        for(int x : b) bsum += x;
        if(p == 1) return dp[u][p] = asum;
        for(int i = 0; i < sz(a); i++) {
            md = min(md, b[i] - a[i]);
        }
        return dp[u][p] = min(asum+1, asum + md) + 1;
    };
    cout << dfs(0, 0, -1, dfs) << '\n';
}

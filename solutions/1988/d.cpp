#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int r = 20;

void dfs(int u, int p, vector<vector<int>> &adj, vector<array<ll, r>> &dp, vector<ll> &a) {
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u, adj, dp, a);
    }
    for(int i = 0; i < r; i++) {
        dp[u][i] = a[u]*(i+1);
        for(int v : adj[u]) {
            if(v == p) continue;
            ll cand = 7e18;
            for(int j = 0; j < r; j++) {
                if(i == j) continue;
                cand = min(cand, dp[v][j]);
            }
            dp[u][i] += cand;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<vector<int>> adj(n);
        for(int i = 0; i < n-1; i++) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<array<ll, r>> dp(n);
        dfs(0, -1, adj, dp, a);
        cout << *min_element(dp[0].begin(), dp[0].end()) << '\n';
    }
}

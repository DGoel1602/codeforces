#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

int mxN = 2e5;
vi cols(mxN);
vi dp(mxN);
vvi adj(mxN);

void dfs1(int u, int p) {
    dp[u] = cols[u];
    for(int v: adj[u]) if(v != p) dfs1(v, u), dp[u] += max(0, dp[v]);
}

void dfs2(int u, int p) {
    dp[u] += max(dp[p] - max(0, dp[u]), 0);
    for(int v: adj[u]) if(v != p) dfs2(v, u);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    rep(i, 0, n) {
        cin >> cols[i];
        if(!cols[i]) --cols[i];
    }
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(0, -1);
    for(int v: adj[0]) dfs2(v, 0);
    rep(i, 0, n) cout << dp[i] << " ";
    cout << "\n";
}

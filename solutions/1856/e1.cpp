#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    vvi adj(n);
    rep(i, 1, n) {
        int p; cin >> p;
        --p;
        adj[p].push_back(i);
    }

    vi sz(n, 0);
    auto dfs = [&](int u, auto&& dfs) -> void {
        sz[u] = 1;
        for(int v: adj[u]) dfs(v, dfs), sz[u] += sz[v];
    };
    dfs(0, dfs);

    int res = 0;
    rep(i, 0, n) {
        vi ch;
        for(int v: adj[i]) ch.push_back(sz[v]);
        int s = accumulate(all(ch), 0);
        vvi dp(ch.size(), vi(s+1, -1));

        auto go = [&](int x, int t, auto&& go) -> int {
            int ot = s - t;
            if(ot < 1) return 0;
            if(x == ch.size()) return t * ot;
            if(dp[x][t] != -1) return dp[x][t];
            return dp[x][t] = max(go(x+1, t, go), go(x+1, t + ch[x], go));
        };
        res += go(0, 0, go);
    }
    cout << res << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

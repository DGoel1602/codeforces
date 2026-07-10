#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

const ll mod = 998244353;

void solve() {
    int n; cin >> n;
    vvi adj(n);
    rep(i, 0, n-1) {
        int p; cin >> p;
        p--;
        adj[p].push_back(i+1);
    }

    vvi depthNs(n + 5);
    int md = 0;
    auto dfs1 = [&](int u, int d, auto &&dfs1) -> void {
        md = max(md, d);
        depthNs[d].push_back(u);
        for(int v: adj[u]) dfs1(v, d+1, dfs1);
    };

    dfs1(0, 0, dfs1);

    vi res(n, 0);
    vi totals(md + 1, 0);
    for(int i = md; i>0; i--) {
        for(int u: depthNs[i]) {
            if (i == md) {
                res[u] = 1;
                totals[i] = (totals[i] + 1) % mod;
                continue;
            }
            res[u] = (totals[i + 1] + 1) % mod;
            for(int v: adj[u]) {
                res[u] = (res[u] + mod - res[v]) % mod;
            }
            totals[i] = (totals[i] + res[u]) % mod;
        }
    }
    cout << (totals[1] + 1) % mod << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

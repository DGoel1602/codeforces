#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

vi sqs(1e7, 0);

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    vvi adj(n);
    rep(i, 0, n-1) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi ssz(n, 1);
    auto dfs = [&](int u, int p, auto&& dfs) -> int {
        for(int v: adj[u]) if(v != p) ssz[u] += dfs(v, u, dfs);
        return ssz[u];
    };

    ll res = 0;
    auto dfs2 = [&](int u, int p, auto&& dfs2) -> void {
        if(sqs[a[u]]) {
            ll bef = 0;
            ll doubles = 0;
            ll triple = 0;
            for (int v : adj[u]) if (v != p) {
                int x = ssz[v];
                triple += doubles * x;
                doubles += bef * x;
                bef += x;
            }
            if(p != -1) {
                int x = n - ssz[u];
                triple += doubles * x;
                doubles += bef * x;
                bef += x;
            }
            res += doubles + triple;
        }
        for(int v: adj[u]) if(v != p) dfs2(v, u, dfs2);
    };
    dfs(0, -1, dfs);
    dfs2(0, -1, dfs2);
    cout << res << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    for(int i = 1; i * i < sqs.size(); i++) sqs[i * i] = 1;

    int t; cin >> t;
    while(t--) solve();
}

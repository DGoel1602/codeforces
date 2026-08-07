#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

struct DSU {
    vi sz, p;
    int n;
    DSU(int n): n(n), sz(n, 1), p(n) {
        iota(all(p), 0);
    }
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return false;
        if(sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    int j; cin >> j;
    DSU dsu(n);
    vector<array<int, 3>> edges;
    ll cost = 0;
    rep(i, 0, m) {
        int u, v, c; cin >> u >> v >> c;
        --u; --v;
        if(i == j - 1) {
            dsu.join(u, v);
            cost += c;
        } else edges.push_back({c, u, v});
    }
    sort(all(edges));
    for(auto [c, u, v]: edges) {
        if(dsu.join(u, v)) cost += c;
    }
    cout << cost << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while(t--) solve();
}

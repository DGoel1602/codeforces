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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n);
    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vi bikes(n);
    for(int &x: bikes) cin >> x;

    vvi dist(n, vi(1001, 1e15));
    priority_queue<array<int, 3>, vector<array<int,3>>, greater<array<int,3>>> pq;
    pq.push({0, 0, 1000});
    dist[0][1000] = 0;
    while(!pq.empty()) {
        auto [c, u, mi] = pq.top(); pq.pop();
        if(u == n - 1) return void(cout << c << "\n");
        int np = min(mi, bikes[u]);
        for(auto [v, w]: adj[u]) {
            if(dist[v][np] <= c + np * w) continue;
            dist[v][np] = c + np * w;
            pq.push({dist[v][np], v, np});
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();
}

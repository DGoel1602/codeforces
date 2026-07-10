#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<ll, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n);
    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,0});
    vi par(n, -1);
    vector<ll> dist(n, 1e16);
    dist[0] = 0;
    while(!pq.empty()) {
        auto [wo, u] = pq.top(); pq.pop();
        if(u == n - 1) {
            vi res;
            int cur = u;
            while(cur != -1) {
                res.push_back(cur);
                cur = par[cur];
            }
            reverse(all(res));
            for(int x: res) cout << x + 1 << " ";
            cout << "\n";

            return 0;
        }
        for(auto [v, w]: adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                par[v] = u;
                pq.push({dist[u]+w,v});
            }
        }
    }
    cout << "-1\n";
}

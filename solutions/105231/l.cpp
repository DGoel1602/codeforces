#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k, t; cin >> n >> m >> k >> t;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    int res = 0;
    set<int> open;
    vector<vector<array<int, 2>>> events(t+2);
    for(int i = 0; i<k; i++) {
        int l, r, p; cin >> p >> l >> r;
        --p;
        events[l].push_back({p, 1});
        events[r+1].push_back({p, -1});
    }

    vector<vector<pair<int, int>>> adj(n);
    for(int i =0 ; i<m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[--u].push_back({--v, w});
        adj[v].push_back({u, w});
    }

    auto eval = [&]() {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;            
            vector<int> dist(n, 1e16);
            for(int x: open) pq.push({0, x}), dist[x] = 0;
            while(!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if(dist[u] < d) continue;
                for(auto [v, w]: adj[u]) {
                    if(dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }           
            }
            res = 0;
            for(int i = 0; i<n; i++) res += a[i] * dist[i];
            if(open.empty()) res = -1;
    };

    eval();

    for(int i = 1; i<=t; i++) {
        for(auto &[p, typ]: events[i]) {
            if(typ == 1) open.insert(p);
            else open.erase(p);
        }
        if(events[i].size()) eval();
        cout << res << '\n';
    }
}

#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)((x).size())
using vi = vector<int>;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, double>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, p;
        cin >> u >> v >> p;
        u--; v--;
        g[u].emplace_back(v, (double)p/100);
        g[v].emplace_back(u, (double)p/100);
    }

    vector<double> dist(n, 1e9), pdist(n), pfail(n, 1);
    dist[n-1] = 0;
    priority_queue<pair<double, int>, vector<pair<double,int>>, greater<>> pq;
    pq.emplace(0, n-1);

    bool f = 0;

    while (sz(pq)) {
        auto [ed, u] = pq.top();
        pq.pop();
        f |= !u;
        if (ed > dist[u]) continue;
        for (auto [v, p] : g[u]) {
            if (dist[v] < ed) continue;
            pdist[v] += pfail[v] * p * dist[u];
            pfail[v] *= (1-p);
            if ((1+pdist[v]) / (1-pfail[v]) < dist[v]) {
                pq.emplace(dist[v] = (1+pdist[v]) / (1-pfail[v]), v);
            }
        }
    }
    if (!f) cout << "impossible\n";
    else cout << fixed << setprecision(10) << dist[0] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    while (T--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define SZ 10

void solve() {
    int n, m; cin >> n >> m;

    int st = 0;
    string sts; cin >> sts;
    for(int i = 0; i<n; i++)
        st = (st << 1) | (sts[i] == '1');

    vector<vector<pair<int, int>>> adj(1 << n);
    for(int j = 0; j<m; j++) {
        int c; cin >> c;
        string rems, adds; cin >> rems >> adds;
        int rem = 0, add = 0;
        for(int i = 0; i<n; i++) {
            rem = (rem << 1) | (rems[i] == '1');
            add = (add << 1) | (adds[i] == '1');
        }
        for(int i = 0; i<(1 << n); i++) {
            int t = (i & (~rem)) | add;
            adj[i].push_back({c, t});
        }
    }

    vector<int> dist(1 << n, 1e9);
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, st});
    while(!pq.empty()) {
        auto [_, u] = pq.top(); pq.pop();
        for(auto [c, v]: adj[u]) {
            if(dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                pq.push({dist[v], v});
            }
        }
    }
    cout << (dist[0] > 1e8 ? -1 : dist[0]) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

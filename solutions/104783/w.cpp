#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct edge {
    int a, b, depth;
};
struct Compare {
    bool operator()(edge &a, edge &b) const {
        return tie(a.depth, a.b, a.a) > tie(b.depth, b.b, b.a);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(n, -1);
    dist[0] = 0;
    queue<int> q; q.push(0);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    priority_queue<edge, vector<edge>, Compare> pq;
    for(int i = 0; i < n; i++) {
        for(int v : adj[i]) {
            if(dist[v] == dist[i]+1) {
                pq.push({i, v, dist[v]});
            }            
        }
    }

    vector<array<int, 30>> jmp(n);

    vector<bool> seen(n, false);
    seen[0] = true;
    jmp[0][0] = 0;

    int cur = 0;
    ll res = 0;

    while(!pq.empty()) {
        auto [a, b, d] = pq.top(); pq.pop();
        if(seen[b]) continue;
        seen[b] = true;
        jmp[b][0] = a;
        for(int k = 1; k < 30; k++) {
            jmp[b][k] = jmp[jmp[b][k-1]][k-1];
        }

        //lca of cur and b
        int next = b;
        int dc = dist[cur], db = dist[next];
        if(dc > db) swap(cur, next);
        int dif = db - dc;
        for(int k = 29; k >= 0; k--) {
            if(dif & (1 << k)) next = jmp[next][k];
        }
        
        int lo = 0, hi = 1000000;
        int lca = -1;

        while(lo < hi) {
            int m = (lo + hi) / 2;
            int nc = cur, nb = next;
            for(int k = 29; k >= 0; k--) {
                if(m & (1 << k)) {
                    nc = jmp[nc][k];
                    nb = jmp[nb][k];
                }
            }
            if(nc == nb) {
                hi = m;
                lca = nc;
            } else lo = m+1;
        }

        assert(lca != -1);
        res += dist[cur] + dist[b] - 2*dist[lca];
        cur = b;
    }
    cout << res << '\n';
}

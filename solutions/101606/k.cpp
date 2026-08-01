#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(a) (int)(a.size())

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); }
    };
    vector<int> lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a])-1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if(v == t || !f) return f;
        for(int& i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if(lvl[e.to] == lvl[v] + 1)
                if(ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        for(int L = 0; L < 31; L++) do {
            lvl = ptr = vector<int>(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while(qi < qe && !lvl[t]) {
                int v = q[qi++];
                for(Edge e : adj[v])
                    if(!lvl[e.to] && e.c >> (30-L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while(ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while(lvl[t]);
        return flow;
    }
};

int main() {
    int n; cin >> n;
    vector<ll> w(n), c(n);
    for(int i = 0; i < n; i++) cin >> w[i] >> c[i];
    int m; cin >> m;
    vector<ll> t(m);
    for(int i = 0; i < m; i++) cin >> t[i];

    Dinic d(2*n + m + 2);
    int source = 2*n + m, sink = 2*n + m + 1;
    for(int i = 0; i < n; i++) {
        if(w[i] == 0) d.addEdge(source, i, 1);
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(w[j] <= c[i]) d.addEdge(n+i, j, 1);
        }
        d.addEdge(i, n+i, 1);
    }
    for(int i = 0; i < m; i++) {
        d.addEdge(2*n + i, sink, 1);
        for(int j = 0; j < n; j++) {
            if(t[i] <= c[j]) d.addEdge(n+j, 2*n+i, 1);
        }
    }

    ll f = d.calc(source, sink);
    if(f != m) {
        cout << "impossible\n";
        return 0;
    }

    vector<vector<int>> res(m);
    for(int b = 0; b < m; b++) {
        int cur = -1;
        for(int i = 0; i < n; i++) {
            for(auto e : d.adj[n+i]) {
                if(e.to == 2*n + b && e.flow()) cur = i;
            }
        }

        while(cur != source) {
            res[b].push_back(cur);
            for(auto e : d.adj[source]) {
                if(e.to == cur && e.flow()) cur = source;
            }
            if(cur == source) break;
            bool done = false;
            for(int i = 0; !done && i < n; i++) {
                for(auto e : d.adj[n+i]) {
                    if(e.to == cur && e.flow()) {
                        cur = i;
                        done = true;
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i < m; i++) {
        reverse(res[i].begin(), res[i].end());
        for(int x : res[i]) cout << x+1 << ' ';
        cout << '\n';
    }
}

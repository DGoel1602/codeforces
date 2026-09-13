#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(a) (int)(a.size())

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc-c, 0LL); }
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
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    int len = sz(s[0]);

    Dinic d(2*n+2);
    int source = 2*n, sink = 2*n+1;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            int dif = 0;
            for(int k = 0; k < len; k++) {
                if(s[i][k] != s[j][k]) dif++;
            }
            if(dif == 2) d.addEdge(i, j+n, 1);
        }
    }

    for(int i = 0; i < n; i++) {
        d.addEdge(source, i, 1);
        d.addEdge(i+n, sink, 1);
    }

    ll f = d.calc(source, sink);
    cout << n - f/2 << endl;
}

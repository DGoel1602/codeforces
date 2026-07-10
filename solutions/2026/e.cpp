#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;
#define sz(x) (int)x.size()
#define rep(i, a, b) for(int i = a; i < b; ++i)

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

#define int ll

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    Dinic dc(n + 67);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<61; j++) {
            if((a[i] >> j) & 1) dc.addEdge(2 + j, 2 + 61 + i, 1);
        }
    }
    for(int i = 0; i<61; i++) dc.addEdge(0, 2 + i, 1);
    for(int i = 0; i<n; i++) dc.addEdge(2 + 61 + i, 1, 1);
    int res = n - dc.calc(0, 1);
    cout << res << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

// 7 1 48 14 13 8 7 6
// 001001 000001 010100 001110 001101 001000 000111 000110

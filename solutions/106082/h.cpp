#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int (i) = (a); (i)<(b); ++(i))

struct MCMF {
	const ll INF = LLONG_MAX >> 2;
	struct edge {
		int v;
		ll cap, flow, cost;
	};
	int n;
	vector<edge> edges;
	vvi adj; vii par; vi in_q;
	vector<ll> dist, pi;
	MCMF(int n): n(n), adj(n), par(n), in_q(n), dist(n), pi(n) {}
	void addEdge(int u, int v, ll cap, ll cost) {
		int idx = sz(edges);
		edges.push_back({v, cap, 0, cost});
		edges.push_back({u, cap, cap, -cost});
		adj[u].push_back(idx);
		adj[v].push_back(idx ^ 1);
	}
	bool findPath(int s, int t) {
		fill(all(dist), INF);
		fill(all(in_q), 0);
		queue<int> q; q.push(s); 
		dist[s] = 0, in_q[s] = 1;
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			in_q[cur] = 0;
			for(int idx: adj[cur]) {
				auto [nxt, cap, fl, wt] = edges[idx];
				ll nxtD = dist[cur] + wt;
				if(fl >= cap || nxtD >= dist[nxt]) continue;
				dist[nxt] = nxtD;
				par[nxt] = {cur, idx};
				if(in_q[nxt]) continue;
				q.push(nxt); in_q[nxt] = 1;
			}
		}

		return dist[t] < INF;
	}
	pair<ll, ll> calc(int s, int t) {
		ll flow = 0, cost = 0;
		while(findPath(s, t)) {
			ll f = INF;
			for(int i, u, v = t; tie(u, i) = par[v], v != s; v = u)
				f = min(f, edges[i].cap - edges[i].flow);
			flow += f;
			for(int i, u, v = t; tie(u, i) = par[v], v != s; v = u)
				edges[i].flow += f, edges[i^1].flow -= f;
		}
		rep(i, 0, sz(edges)>>1)
			cost += edges[i<<1].cost * edges[i<<1].flow;
 
		return {flow, cost};
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, s, k; cin >> n >> s >> k;
	MCMF mcmf(2 + n + s);
	int c = 0;
	rep(i, 0, n)
		mcmf.addEdge(0, 2 + i, 1, 0);
	for(int i = 0; i<n; i++) {
		ll mx = 0;
		for(int j = 0; j<s; j++) {
			ll x; cin >> x;
			mcmf.addEdge(2 + i, 2 + n + j, 1, -x);
			mx = max(mx, x);
			c++;
		}
		mcmf.addEdge(2 + i, 1, 1, 1e7-mx);
	}
	for(int j = 0; j<s; j++)
		mcmf.addEdge(2 + n + j, 1, k, 0);
	auto res = mcmf.calc(0, 1);
	ll ret = -res.second;
	cout << ret + (n - s * k) * 1e7 << endl;
}

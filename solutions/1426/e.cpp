#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

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

int a[3], b[3];
int n;
void solve() {
    MCMF mcmf(8);
    auto [r, p, s] = a;
    mcmf.addEdge(0, 1, r, 0);
    mcmf.addEdge(1, 4, r, 0);
    mcmf.addEdge(1, 5, r, 0);
    mcmf.addEdge(1, 6, r, -1);

    mcmf.addEdge(0, 2, p, 0);
    mcmf.addEdge(2, 4, p, -1);
    mcmf.addEdge(2, 5, p, 0);
    mcmf.addEdge(2, 6, p, 0);

    mcmf.addEdge(0, 3, s, 0);
    mcmf.addEdge(3, 4, s, 0);
    mcmf.addEdge(3, 5, s, -1);
    mcmf.addEdge(3, 6, s, 0);

    mcmf.addEdge(4, 7, b[0], 0);
    mcmf.addEdge(5, 7, b[1], 0);
    mcmf.addEdge(6, 7, b[2], 0);

    auto res = mcmf.calc(0, 7);
    cout <<  - res.second << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    MCMF mcmf(8);
    cin >> a[0] >> a[2] >> a[1];
    cin >> b[0] >> b[2] >> b[1];

    auto [r, p, s] = a;
    mcmf.addEdge(0, 1, r, 0);
    mcmf.addEdge(1, 4, r, -1);
    mcmf.addEdge(1, 5, r, -1);
    mcmf.addEdge(1, 6, r, 0);

    mcmf.addEdge(0, 2, p, 0);
    mcmf.addEdge(2, 4, p, 0);
    mcmf.addEdge(2, 5, p, -1);
    mcmf.addEdge(2, 6, p, -1);

    mcmf.addEdge(0, 3, s, 0);
    mcmf.addEdge(3, 4, s, -1);
    mcmf.addEdge(3, 5, s, 0);
    mcmf.addEdge(3, 6, s, -1);

    mcmf.addEdge(4, 7, b[0], 0);
    mcmf.addEdge(5, 7, b[1], 0);
    mcmf.addEdge(6, 7, b[2], 0);

    auto res = mcmf.calc(0, 7);
    cout << n + res.second << " ";
    solve();
}

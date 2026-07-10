#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

struct DSU {
	int n;
	vi p, siz;
	DSU(int n): n(n), p(n), siz(n, 1) {
		iota(all(p), 0);
	}
	int find(int x) {
		if(p[x] != x) p[x] = find(p[x]);
		return p[x];
	}
	bool join(int u, int v) {
		u = find(u), v = find(v);
		if(u == v) return false;
		if(siz[u] < siz[v]) swap(u, v);
		p[v] = u;
		siz[u] += siz[v];
		return true;
	}
};

void solve() {
	int n, m; cin >> n >> m;
	vvi adj(n);
	vector<array<int, 3>> edges;
	rep(i, 0, m) {
		int u, v, c; cin >> u >> v >> c;
		--u; --v;
		edges.push_back({c, u, v});
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	sort(all(edges), greater<>());

	DSU dsu(n);
	array<int, 3> best;
	for(auto [c, u, v]: edges)
		if(!dsu.join(u, v)) best = {c, u, v};

	vi par(n, -1);
	vi dist(n, -1);
	auto [c, st, en] = best;
	dist[st] = 0;
	queue<int> q;
	q.push(st);
	while(!q.empty()) {
		auto u = q.front(); q.pop();
		for(int v: adj[u]) {
			if(u == st && v == en) continue;
			if(u == en && v == st) continue;
			if(dist[v] == -1) {
				dist[v] = dist[u] + 1;
				par[v] = u;
				q.push(v);
			}
		}
	}
	vi path;
	int cur = en;
	while(cur != -1) {
		path.push_back(cur);
		cur = par[cur];
	}
	cout << c << " " << path.size() << '\n';
	for(int x: path) cout << x + 1 << ' ';
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

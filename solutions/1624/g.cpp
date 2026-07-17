#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

struct DSU {
	int n, cs;
	vi sz, p;
	DSU(int n): cs(n), n(n), sz(n, 1), p(n) {
		iota(all(p), 0);
	}
	int find(int x) {
		if(p[x] != x) p[x] = find(p[x]);
		return p[x];
	}
	void join(int a, int b) {
		a = find(a), b = find(b);
		if(a == b) return;
		if(sz[a] < sz[b]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
		cs--;
	}
};

void solve() {
	int n, m; cin >> n >> m;
	vector<array<int, 3>> edges(m);
	for(auto &[u, v, c]: edges) cin >> u >> v >> c, --u, --v;
	for(int bit = 30; bit >= 0; bit--) {
		DSU dsu(n);
		vector<array<int, 3>> edges2;
		for(auto [u, v, c]: edges) if(!(c & (1 << bit))) edges2.push_back({u, v, c}), dsu.join(u, v);
		if(dsu.cs == 1) swap(edges2, edges);
	}
	int res = 0;
	for(auto [u, v, c]: edges) res |= c;
	cout << res << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

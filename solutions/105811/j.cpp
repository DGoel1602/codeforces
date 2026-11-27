#include <bits/stdc++.h>
#include <queue>
using namespace std;

int n, m; 

vector<int> dists(map<int, vector<array<int, 2>>> adj) {
	set<int> reached;
	vector<int> a_dist(n, 1e9);
	int mx = 0;
	vector<vector<int>> add(n);

	auto inc = [&](int u, auto&& inc) -> void {
		if(reached.count(u)) return;
		reached.insert(u);
		a_dist[u] = mx;
		for(int v: add[u]) inc(v, inc);
	};
	inc(0, inc);

	for(auto [c, vec]: adj) {
		mx = max(mx, c);
		for(auto [u, v]: vec) {
			if(reached.count(u) && reached.count(v)) continue;

			if(reached.count(u)) {
				inc(v, inc);
			} else {
				add[u].push_back(v);
			}
		}
	}
	return a_dist;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	map<int, vector<array<int, 2>>> adj, radj;
	for(int i = 0; i<m; i++) {
		int u, v, w; cin >> u >> v >> w;
		--u; --v;
		adj[w].push_back({u, v});
		radj[w].push_back({v, u});
	}

	vector<int> a_dist = dists(adj), a_dist2 = dists(radj);

	for(int i = 0; i<n; i++)
		if(a_dist[i] < a_dist2[i]) return (cout << "NO\n", 0);
	cout << "YES\n";
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) (x).begin(), (x).end()

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vi a(n), b(n);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;
	vector<vi> adj(n);
	for(int i = 0; i<(n-1); i++) {
		int u, v; cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	auto dfs = [&](int u, int p, int cur, auto&& dfs) -> pii {
		pii m = {a[u], b[u]};
		vector<pii> ops;
		for(int v: adj[u]) if(v != p) {
			pii ch = dfs(v, u, cur^1, dfs);
			ops.push_back(ch);
		}
		sort(ops.begin(), ops.end(), [&](auto a, auto b) -> bool {
				if(cur) {
					pii c = {a.second, a.first};
					pii d = {b.second, b.first};
					return c < d;
				} else return a < b;
		});
		if(ops.size()) {
			m.first += ops.back().first;
			m.second += ops.back().second;
		}
		return m;
	};
	pii res = dfs(0, -1, 0, dfs);
	cout << res.first << " " << res.second << '\n';
}

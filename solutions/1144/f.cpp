#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n, m; cin >> n >> m;
	vvi adj(n);
	vector<pii> edges(m);
	rep(i, 0, m) {
		int u, v; cin >> u >> v;
		--u; --v;
		edges[i] = {u, v};
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vi res(n);
	auto go = [&](int u, int c, auto&& go) -> bool {
		if(res[u]) return res[u] == c;
		res[u] = c;
		for(int v: adj[u]) if(!go(v, c * -1, go)) return false;
		return true;
	};
	if(!go(0, 1, go)) return void(cout << "NO\n");
	cout << "YES\n";
	rep(i, 0, m) cout << (res[edges[i].first] == 1);
	cout << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while(t--) solve();
}

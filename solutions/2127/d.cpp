#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

vi facts(3e5, 1LL);

const ll mod = 1e9 + 7;

void solve() {
	int n, m; cin >> n >> m;

	vvi adj(n);
	rep(i, 0, m) {
		int u, v; cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if(m != n - 1) return void(cout << "0\n");

	vi type(n, -1);
	auto dfs = [&](int u, int c, auto&& dfs) -> int {
		type[u] = c;
		for(int v: adj[u]) {
			if(type[v] != -1 && type[v] == c) return 0;
			if(type[v] == -1) dfs(v, c ^ 1, dfs);
		};
		return 1;
	};

	if(!dfs(0, 0, dfs)) return void(cout << "0\n");

	vvi dadj(n);
	rep(i, 0, n) {
		for(int v: adj[i]) if(adj[v].size() > 1) {
			dadj[i].push_back(v);
			if(dadj[i].size() > 2) return void(cout << "0\n");
		}
	}

	vi nl;
	rep(i, 0, n) {
		if(adj[i].size() > 1) nl.push_back(adj[i].size() - dadj[i].size());
	}

	int res = 1;
	for(int x: nl) res = (res * facts[x]) % mod;
	if(sz(nl) > 1) res = (2 * res) % mod;
	cout << (2 * res) % mod << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	for(int i = 2; i<3e5; i++) facts[i] = (facts[i-1] * i) % mod;
	int t; cin >> t;
	while(t--) solve();
}

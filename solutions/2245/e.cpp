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

void solve() {
	int n; cin >> n;
	vvi adj(n);
	rep(i, 0, n-1) {
		int u, v; cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vi num(n);
	auto dfs = [&](int u, int p, auto&& dfs) -> void {
		if(adj[u].size() % 2 == 0) num[u] = 1;
		for(int v: adj[u]) if(v != p) dfs(v, u, dfs);
	};
	dfs(0, -1, dfs);

	vi cnts(n);
	ll tres = 0;
	auto dfs2 = [&](int u, int p, int i, auto&& dfs2) -> void {
		int works = 0;
		for(int v: adj[u]) works += adj[v].size() % 2;
		if(num[u]) cnts[i] += works;
		if(!num[u]) tres += works;
		for(int v: adj[u]) if(v != p) dfs2(v, u, num[u] ? i : v, dfs2);
	};
	dfs2(0, -1, 0, dfs2);
	tres /= 2;
	
	for(int x: cnts) {
		if(x) tres += (x * (x - 1)) / 2;
	}
	cout << tres << '\n';

	dfs(0, -1, dfs);
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

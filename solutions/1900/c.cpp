#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	string val; cin >> val;
	vector<array<int, 2>> adj(n, {-1, -1});
	rep(i, 0, n) {
		int a, b; cin >> a >> b;
		--a, adj[i][0] = a;
		--b, adj[i][1] = b;
	}
	auto dfs = [&](int u, auto&& dfs) -> int {
		if(u == -1) return 1e9;
		if(adj[u][0] == adj[u][1] && adj[u][0] == -1) return 0;
		return min(
				(val[u] != 'L') + dfs(adj[u][0], dfs),
				(val[u] != 'R') + dfs(adj[u][1], dfs)
		);
	};
	cout << dfs(0, dfs) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

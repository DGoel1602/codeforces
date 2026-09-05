#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 0; i<n-1; i++) {
		int u, v; cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	auto dfs = [&](int u, int p, auto&& dfs) -> double {
		double res = 0;
		for(int v: adj[u]) if(v != p) res += 
			(1 + dfs(v, u, dfs)) / (adj[u].size() - (p != -1));
		return res;
	};

	cout << fixed << setprecision(10) << dfs(0, -1, dfs) << '\n';
}

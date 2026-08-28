#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	vvi adj(n);
	rep(i, 1, n) {
		int p; cin >> p;
		--p;
		adj[p].push_back(i);
	}
	int nb = -1;
	int m; cin >> m;
	vi a(m);
	for(int &x: a) cin >> x, --x;
	vi cnt(n);
	for(int x: a) cnt[x]++;
	auto dfs = [&](int u, int ph, auto&& dfs) -> void {
		if(cnt[u] && !ph) nb = u;
		for(int v: adj[u]) dfs(v, ph | cnt[u], dfs);
	};
	dfs(0, 0, dfs);
	cout << m - 1 << ' ';
	for(int x: a) if(x != nb) cout << x + 1 << ' ';
	cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

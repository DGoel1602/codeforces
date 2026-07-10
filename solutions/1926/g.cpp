#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
	int n; cin >> n;
	vvi adj(n);
	rep(i, 1, n) {
		int p; cin >> p;
		--p;
		adj[p].push_back(i);
	}

	vi col(n);
	rep(i, 0, n) {
		char c; cin >> c;
		if(c == 'P') col[i] = 1;
		else if(c == 'S') col[i] = -1;
	}

	vvi dp(n, vi(3, -1));

	auto go = [&](int u, int c, auto&& go) -> int {
		auto &ref = dp[u][c+1];
		if(ref != -1) return ref;
		ref = 0;
		if(col[u]) {
			for(int v: adj[u]) ref += go(v, col[u], go);
			ref += (col[u] != c);
		} else if(!col[u]) {
			int r1 = 1, r2 = 0;
			for(int v: adj[u]) r1 += go(v, c == 1 ? -1 : 1, go), r2 += go(v, c, go);
			ref = min(r1, r2);
		}
		return ref;
	};

	if(col[0]) cout << go(0,  col[0], go) << '\n';
	else {
		cout << min(go(0, -1, go), go(0, 1, go)) << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

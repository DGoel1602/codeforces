#include <bits/stdc++.h>
#include <numeric>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	vi cnt(n);
	vector<pii> edges;
	rep(i, 0, n-1) {
		int u, v; cin >> u >> v;
		--u; --v;
		edges.push_back({u, v});
		cnt[u]++; cnt[v]++;
	}
	int f = -1;
	rep(i, 0, n) if(cnt[i] >= 3) f = i;
	vi res(n-1, -1);
	int cur = 0;
	rep(i, 0, n-1) {
		auto [u, v] = edges[i];
		if(u == f || v == f) res[i] = cur++;
	}
	rep(i, 0, n-1) if(res[i] == -1) res[i] = cur++;
	for(int x: res) cout << x << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while(t--) solve();
}

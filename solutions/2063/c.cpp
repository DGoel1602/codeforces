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
	set<pair<int, int>> edges;
	vi cnt(n);
	rep(i, 0, n-1) {
		int u, v; cin >> u >> v;
		--u; --v;
		cnt[v]++; cnt[u]++;
		edges.insert({u, v});
		edges.insert({v, u});
	}
	vector<pii> ord;
	rep(i, 0, n) ord.push_back({-cnt[i], i});
	sort(all(ord));
	int be = (n == 2 ? 0 : 1);
	for(int i = 0; i<n; i++) {
		for(int j = i+1; j<n; j++) {
			if(!edges.count({ord[i].second,ord[j].second})) {
				be = max(be, - ord[i].first - ord[j].first - 1);
				break;
			}
			be = max(be, - ord[i].first - ord[j].first - 2);
		}
	}
	cout << be << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

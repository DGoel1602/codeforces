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
	vi a(n);
	for(int &x: a) cin >> x;
	sort(all(a));

	vvi dp(2 * n + 1, vi(n, -1));
	auto go = [&](int t, int i, auto&& go) -> int {
		if(i == n) return 0;
		if(t == 2 * n + 1) return 1e9;
		auto &ref = dp[t][i];
		if(ref != -1) return ref;
		return ref = min(abs(a[i] - t) + go(t+1, i+1, go), go(t+1, i, go));
	};
	cout << go(1, 0, go) << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

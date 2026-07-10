#include <algorithm>
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
	int n, l, r; cin >> n >> l >> r;
	vi a(n);
	for(int &x: a) cin >> x;
	vi pref(n+1);
	for(int i = 1; i<=n; i++) pref[i] = pref[i-1] + a[i-1];

	vi dp(n+1, 0);
	for(int i = n-1; i>=0; i--) {
		dp[i] = dp[i+1];
		auto ls = lower_bound(all(pref), pref[i] + l);
		if(ls == pref.end()) continue;
		if(pref[ls - pref.begin()] > pref[i] + r) continue;
		dp[i] = max(dp[i], 1 + dp[ls - pref.begin()]);
	}

	cout << dp[0] << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

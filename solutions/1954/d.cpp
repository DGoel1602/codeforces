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

const ll mod = 998244353;

ll modpow(ll b, ll e) {
	ll res = 1;
	for(; e; b = (b * b) % mod, e /= 2)
		if(e & 1) res = (res * b) % mod;
	return res;
}

void solve() {
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;

	vector<int> cnts(12000);
	cnts[0] = 1;
	sort(all(a));

	ll res = 0;
	ll tot_rem = 0;

	int useodds = 0;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<a[i]; j++) {
			tot_rem = (tot_rem + ((a[i] + j) * cnts[j]) % mod) % mod;
			res = (res + (cnts[j] * a[i]) % mod) % mod;
			if((a[i] + j) % 2) useodds = (useodds + cnts[j]) % mod;
		}
		for(int j = 12000; j>=0; j--) {
			if(j + a[i] >= 12000) continue;
			cnts[j+a[i]] = (cnts[j+a[i]] + cnts[j]) % mod;
		}
	}

	vector<pii> dp(n+1);
	int nodds = 0, nevens = 1;
	dp[0] = {0, 1};
	for(int i = 0; i<n; i++) {
		dp[i+1].first = (dp[i].first + (dp[i].first + (a[i] * dp[i].second) % mod) % mod) % mod;
		dp[i+1].second = (dp[i].second * 2) % mod;

		int oo = nodds;
		if(a[i] % 2) nodds = (nodds + nevens) % mod;
		else nodds = (nodds + nodds) % mod;
		if(a[i] % 2) nevens = (nevens + oo) % mod;
		else nevens = (nevens + nevens) % mod;
	}

	int exodds = (((nodds + mod - useodds)) % mod * modpow(2, mod-2)) % mod;

	int tot = (dp[n].first + mod - tot_rem) % mod;
	cout << (tot * modpow(2, mod-2) + res + exodds) % mod << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	solve();
}

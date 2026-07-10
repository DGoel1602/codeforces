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

vi sieve(1e5, 1);
vi primes;

void solve() {
	int n; cin >> n;
	vi a(n), b(n), c(n);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;

	int res = 0;
	for(int i = 0; i<n; i++) {
		int f = (i > 0 ? __gcd(a[i-1], a[i]) : 1);
		int s = (i < (n-1) ? __gcd(a[i+1], a[i]) : 1);
		int lcm = f * s / __gcd(f, s);

		c[i] = (lcm <= b[i] ? lcm : a[i]);
	}

	vvi aps(n);

	rep(i, 0, n) {
		if(c[i] == a[i]) {
			int f = (i > 0 ? __gcd(a[i-1], a[i]) : 1);
			int s = (i < (n-1) ? __gcd(a[i+1], a[i]) : 1);

			int ot1 = (i > 0 ? c[i-1] / f : 1);
			int ot2 = (i < (n-1) ? c[i+1] / s : 1);
			for(int p: primes) {
				if(c[i] * p > b[i] || aps[i].size() > 10) break;
				if(ot1 % p == 0 || ot2 % p == 0) continue;
				aps[i].push_back(p);
			}
		}
	}

	map<pair<int, int>, int> dp;
	auto go = [&](int i, int lp, auto&& go) -> int {
		if(i == n) return 0;
		if(dp.count({i, lp})) return dp[{i, lp}];

		int mr = c[i] <= b[i] && c[i] != a[i];
		auto &ref = dp[{i, lp}];
		ref = mr + go(i+1, 1, go);

		if(c[i] == a[i]) {
			for(int p: aps[i]) if(p != lp) {
				mr = c[i] * p <= b[i];
				ref = max(ref, mr + go(i+1, p, go));
			}
		}
		return ref;
	};
	cout << go(0, 1, go) << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	rep(i, 2, 1e5) {
		if(!sieve[i]) continue;
		for(int j = i * i; j<1e5; j += i) sieve[j] = 0;
		primes.push_back(i);
	}

	int t; cin >> t;
	while(t--) solve();
}

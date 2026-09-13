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
	for(; e; b = (b * b) % mod, e >>= 1) 
		if(e & 1) res = (res * b) % mod;
	return res;
}

void solve() {
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;
	sort(all(a), greater<>());
	int sum = a[0];
	int res = 0, cnt = 1;
	rep(i, 1, n) {
		res = (res * i) % mod;
		cnt = (cnt * i) % mod;
		res = (res - (cnt * a[i]) % mod + mod + 
				(
				 (modpow(i, mod-2) * sum) % mod
				 * cnt) % mod) % mod;
		sum = (sum + a[i]) % mod;
	}
	cout << res << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

// c = 1
//    4
// 	/
// 3

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 998244353;

using ll = long long;

ll modpow(ll b, ll e) {
	ll res = 1;
	for(; e; b = (b * b) % mod, e/=2)
		if(e & 1) res = (res * b) % mod;
	return res;
}

void solve() {
	int n, k, p; cin >> n >> k >> p;
	ll r = (k * p) % mod;
	ll q = (1 + mod - p) % mod;
	if((k * p) % mod == 1) {
		ll res = (n + ((q * (n * (n - 1)) % mod) % mod 
				* modpow(2, mod-2))) % mod;
		res = (res * q) % mod;
		cout << res << '\n';
		return;
	}
	ll rn = modpow(r, n);
	ll div = (((rn + mod - 1) % mod) 
		* modpow((r + mod - 1) % mod, mod - 2)) % mod;
	ll qr1 = (q * modpow((r + mod - 1) % mod, mod - 2)) % mod;
	ll rt = (qr1 * ((div + mod - n) % mod)) % mod;
	ll ft = (div + rt) % mod;
	ft = (ft * q) % mod;
	cout << ft << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

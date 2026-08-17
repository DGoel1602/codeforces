#include <bits/stdc++.h>
using namespace std;

using ll = __uint128_t;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

const ll mod = 1000000007;

ll modpow(ll b, ll e) {
	ll res = 1;
	for(; e; b = (b * b) % mod, e /= 2)
		if(e & 1) res = (res * b) % mod;
	return res;
}

void solve() {
	long long n, m, k; cin >> n >> m >> k;
	if(n % 2 != m % 2 && k == -1) return void(cout << "0\n");
	ll pow = max((ll)0, (ll)(n - 1) * (ll)(m - 1));
	cout << (long long)modpow(2, pow) << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while(t--) solve();
}

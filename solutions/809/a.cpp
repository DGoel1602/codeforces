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

const ll mod = 1e9 + 7;
ll modpow(ll b, ll e) {
	ll res = 1;
	for(; e; b = (b * b) % mod, e /= 2)
		if(e & 1) res = (res * b) % mod;
	return res;
}

void solve() {
	int n; cin >> n;
	ll sum = 0;
	vi a(n);
	for(int &x: a) cin >> x;
	sort(all(a));
	ll res = 0;
	rep(i, 0, n) {
		res = (res + ((modpow(2, i) - 1) * a[i]) - sum) % mod;
		sum = (sum * 2) % mod;
		sum = (sum + a[i]) % mod;
	}
	cout << res << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while(t--) solve();
}

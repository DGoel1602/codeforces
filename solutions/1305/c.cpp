#include <bits/stdc++.h>
#include <numeric>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

ll mod;

ll modpow(ll b, ll e) {
	ll res = 1;
	for(; e; b = (b * b) % mod, e /= 2) 
		if(e & 1) res = (res * b) % mod;
	return res;
}

void solve() {
	int n, m; cin >> n >> m;
	mod = m;
	vi a(n);
	for(int &x: a) cin >> x;
	sort(all(a));
	for(int &x: a) x %= m;
	vi cnt(1000);
	ll res = 1;
	vvi ts(1000, vi(1000, 0));
	rep(i, 0, n) {
		rep(j, 0, 1000)
			ts[a[i]][j] += cnt[j];
		cnt[a[i]]++;
	}
	rep(i, 0, 1000) rep(j, 0, 1000) {
		res = (res * modpow((i + m - j) % m, ts[i][j])) % m;
	}
	cout << res << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while(t--) solve();
}

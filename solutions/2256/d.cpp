#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

const ll mod = 998244353;

vector<ll> facts(2e6+1, 1);

ll modpow(ll b, ll e) {
	ll res = 1;
	for(; e; b = (b * b) % mod, e /= 2) 
		if(e & 1) res = (res * b) % mod;
	return res;
}

ll choose(ll n, ll k) {
	if(k < 0) return 1;
	return (facts[n] * modpow((facts[k] * facts[n-k]) % mod, mod - 2)) % mod;
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	vector<ll> cnt(2), ext(2);
	rep(i, 0, n) {
		if(i == 0 || s[i] != s[i-1]) cnt[(s[i]-'0')]++;
		else ext[s[i]-'0']++;
	}
	ll res = (choose(cnt[0] + ext[0] - 1, cnt[0] - 1) * choose(cnt[1] + ext[1] - 1, cnt[1] - 1)) % mod;
	cout << res << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
		rep(i, 1, 2e6+1) facts[i] = (facts[i-1] * i) % mod;
    int t; cin >> t;
    while(t--) solve();
}

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

vi sieve(1e6+2, 1);
vi primes;

const ll mod = 1e9+7;

void solve() {
	int n, _; cin >> n >> _;
	vi a(n);
	for(int &x: a) cin >> x;

	map<int, int> freqs;
	for(int x: a) {
		for(int p: primes) {
			if(p * p > x) break;
			while(x % p == 0) x /= p, freqs[p]++;
		}
		if(x > 1) freqs[x]++;
	}

	ll res = 1;
	for(auto [p, cnt]: freqs) {
		res = (res * (cnt + 1)) % mod;
	}
	cout << res << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	rep(i, 2, 1e6) {
		if(!sieve[i]) continue;
		for(int j = i * i; j <= 1e6; j += i) sieve[i] = 0;
		primes.push_back(i);
	}
	int t; cin >> t;
	while(t--) solve();
}

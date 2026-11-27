#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

using ll = long long;
#define int __int128_t
using vi = vector<int>;

#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define sz(x) (int)(x).size()

const ll mod = 1e9 + 7;

int modpow(int b, int e) {
	int res = 1;
	for(; e; b=(b*b)%mod, e/=2) 
		if(e & 1) res = (res*b)%mod;
	return res;
}

int check(int n) {
	int res = 0;
	for(int i = 1; i<=n; i++) res = (res + ((n*i) % mod * modpow(__gcd(n, i), mod-2)) % mod) % mod;
	return res;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	ll _n; cin >> _n;
	int n = _n;

	vector<int> divs;
	for(int i = 1; i*i<=n; i++) {
		if(n % i == 0) {
			divs.push_back(i);
			if(i * i != n) divs.push_back(n / i);
		}
	}
	sort(all(divs));

	vector<int> sums(sz(divs));
	for(int i = 0; i<sz(sums); i++) {
		int cnt = n / divs[i];
		int tt = (((cnt*(cnt+1)) % mod) * modpow(2, mod-2)) % mod;
		sums[i] = (divs[i] * tt) % mod;
	}

	for(int i = sz(sums)-1; i>=0; i--) {
		for(int j = i+1; j<sz(sums); j++) 
			if(divs[j] % divs[i] == 0) sums[i] = (sums[i] + mod - sums[j]) % mod;
	}

	ll fn = 0;
	for(int i = 0; i<sz(sums); i++) {
		fn = (fn + (sums[i] * (n / divs[i])) % mod) % mod;
	}
	cout << fn << '\n';
	//assert(fn == check(n));
}

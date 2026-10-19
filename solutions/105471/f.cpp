#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < b; ++i)

using vi = vector<int>;
using ll = long long;
#define int ll
ll n;


const ll mod = (119 << 23) + 1, root = 62; // = 998244353

ll modpow(ll b, ll e) {
	ll res = 1;
	for(; e; b = (b * b) % mod, e >>=1) 
		if(e & 1) res = (res * b) % mod;
	return res;
}

ll modpow_n(ll b, ll e) {
	ll res = 1;
	for(; e; b = (b * b) % n, e >>=1) 
		if(e & 1) res = (res * b) % n;
	return res;
}
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
typedef vector<ll> vl;
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, mod >> s)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = modpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

vl cyclic(const vl &a, const vl &b) {
	vl res = conv(a, b);
	vl out(n-1);
	for(int i =0 ; i<res.size(); i++) {
		out[(i%(n-1))] = (out[i%(n-1)] + res[i]) % mod;
	}
	return out;
}

vector<ll> facts;
vector<int> sieve(5000, 1);
vector<int> primes;
ll choose(ll a, ll b) {
	return (facts[a] * modpow_n(facts[b] * facts[a - b], n-2)) % n;
}

void solve(string k, int x) {
	facts.resize(n);
	facts[0] = 1;
	for(int i = 1; i<n; i++) facts[i] = (facts[i-1] * i) % n;

	vector<ll> a(n);
	for(int i = 0; i<n; i++)
		for(int j = 0; j<=i; j++)
			a[choose(i, j)]++;

	vector<int> ps;
	for(int p: primes)
		if((n-1)%p==0) ps.push_back(p);

	int pr = 2;
	auto works = [&](int tr) -> bool {
		for(int p: ps) {
			if(modpow_n(tr, n/p) == 1) return false;
		}
		return true;
	};
	while(!works(pr)) pr++;

	vector<int> idx(n);
	int cur = 1;
	for(int i = 0; i<n-1; i++) {
		idx[cur] = i;
		cur = (cur * pr) % n;
	}

	vector<ll> arr(n-1);
	for(int i = 1; i<n; i++) arr[idx[i]] = a[i];
	swap(arr, a);

	vl ans(n-1);
	ans[0] = 1;

	for(int i = k.size()-1; i>=0; i--) {
		if(k[i] == '1') ans = cyclic(ans, a);
		a = cyclic(a, a);
	}

	cout << ans[idx[x]] << '\n';
}


signed main() {
	cin.tie(0)->sync_with_stdio(0);
	for(int i = 2; i<5000; i++) {
		if(sieve[i] == 0) continue;
		for(int j = i*i; j<5000; j+=i) sieve[j] = 0;
		primes.push_back(i);
	}

	string k;
	ll x; cin >> k >> n >> x;
	solve(k, x);
}

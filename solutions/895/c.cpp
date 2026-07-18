#include <algorithm>
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

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;
	int mx = *max_element(all(a));

	vi primes;
	vi idxs(mx+1);
	for(int i = 2; i<mx+1; i++) {
		for(int j = 2; j * j <= i; j++) if(i % j == 0) goto next;
		primes.push_back(i);
		idxs[i] = primes.size()-1;
		next:;
	}

	vi freq(mx+1, 0);
	for(int x: a) freq[x]++;
	vi ps(mx+1);
	for(int i = 1; i<mx+1; i++) {
		int oi = i;
		for(int p: primes) {
			if(p * p > oi) break;
			while(oi % p == 0) ps[i] ^= (1 << idxs[p]), oi /= p;
		}
		if(oi > 1) ps[i] ^= (1 << idxs[oi]);
	}

	vector<int> dp(1 << 19, 0);
	vector<int> dp2(1 << 19, 0);
	dp[0] = dp2[0] = 1;

	for(int i = mx; i>=1; i--) {
		for(int cur = 0; cur<(1 << 19); cur++) {
			if(!freq[i]) dp2[cur] = dp[cur];
			else
				dp2[cur] = (modpow(2, freq[i]-1) * (dp[cur] + dp[cur^ps[i]]) % mod) % mod;
		}
		swap(dp, dp2);
	}
	cout << dp[0] - 1 << '\n';
}

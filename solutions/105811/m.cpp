#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;

#define all(x) (x).begin(), (x).end()

const ll mod = 1e9 + 7;

ll modpow(ll b, ll e) {
	ll res = 1;
	for(; e; b = (b*b)%mod, e/=2)
		if(e & 1) res = (res * b) %mod;
	return res;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;

	ll sz = 330;
	vector<ll> dp(110000);
	int mx = (min(sz, n)+1)*(min(sz, n)+1);
	for(int i = 0; i<=mx; i++) dp[i] = 1;
	vector<ll> dp2(110000);
	
	for(int i = min(sz-1, n-1); i >= 0; i--) {
		for(int cur = 110000-1; cur>=0; cur--) {
			int mx = (i+1)*(i+1);
			if(a[i] + cur <= mx) dp2[cur] = (dp2[cur] + dp[a[i]+cur]) % mod;
			if(cur <= mx) dp2[cur] = (dp2[cur] + dp[cur]) % mod;
		}
		swap(dp, dp2);
		dp2 = vector<ll>(110000, 0);

		//for(int k = 0; k<10; k++) cout << dp[k] << " ";
		//cout << endl;
	}

	cout << (dp[0] * modpow(2, max(0LL, n - sz))) % mod << '\n';
}

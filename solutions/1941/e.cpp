#include <bits/stdc++.h>
#include <set>
using namespace std;

using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll t; cin >> t;
	while(t--) {
		ll n, m, k, d; cin >> n >> m >> k >> d;
		vector<ll> costs(n);
		for(ll row = 0; row<n; row++) {
			multiset<ll> lasts;
			lasts.insert(1);

			vector<ll> dp(m, 1e15);
			dp[0] = 1;

			vector<ll> depths(m, -1);
			for(ll &x: depths) cin >> x;

			for(ll i = 1; i<m; i++) {
				dp[i] = *(lasts.begin()) + depths[i] + 1;
				lasts.insert(dp[i]);
				if(lasts.size() > d + 1) lasts.erase(lasts.lower_bound(dp[i - d - 1]));
			}
			costs[row] = dp[m-1];
		}
		ll cur = 0;
		for(ll i = 0; i<k; i++) cur += costs[i];
		ll best = cur;
		for(ll i = k; i<n; i++) {
			cur += costs[i];
			cur -= costs[i - k];
			best = min(best, cur);
		}
		cout << best << endl;
	}
}

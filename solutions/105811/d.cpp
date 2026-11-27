#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define all(x) (x).begin(), (x).end()

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, d; cin >> n >> d;
	vector<array<ll, 2>> a(n);
	for(auto &[c, d]: a) cin >> c >> d;
	sort(all(a));

	vector<ll> dp(n+1);
	for(int i = n-1; i>=0; i--) {
		int lo = i+1, hi = n;
		while(lo != hi) {
			int m = lo + (hi - lo) / 2;
			if(a[m][0] - a[i][0] < d) lo = m + 1;
			else hi = m;
		}
		dp[i] = max(dp[i+1], a[i][1] + dp[lo]);
	}
	cout << dp[0] << '\n';
}

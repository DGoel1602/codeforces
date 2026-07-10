#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	vi a(n), c(n);
	for(int &x: a) cin >> x;
	for(int &x: c) cin >> x;
	vector<ll> dp(n);
	rep(i, 0, n) {
		dp[i] = c[i];
		rep(j, 0, i) if(a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + c[i]);
	}
	cout << accumulate(all(c), 0ll) - *max_element(all(dp)) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

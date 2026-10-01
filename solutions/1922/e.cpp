#include <bits/stdc++.h>
#include <cassert>
#include <numeric>
using namespace std;

#define int long long

int fuzz(vector<int> &a) {
	vector<int> dp(a.size());
	for(int i = 0; i<a.size(); i++) {
		for(int j = 0; j<i; j++) if(a[j] < a[i]) dp[i] += dp[j];
		dp[i]++;
	}
	return accumulate(dp.begin(), dp.end(), 0LL) + 1;
}

void solve() {
	int res = 1;
	vector<pair<int, int>> cnts;
	int n; cin >> n;

	int cur = 0, cnt = 0;
	while(2*cur+1+1 <= n) {
		cnts.push_back({cur + 1, cnt++});
		cur = 2 * cur + 1;
	}
	cur++;

	int lf = n - cur;

	vector<int> fn;
	for(int i = 0; i<cnts.size(); i++) fn.push_back(i * 1000);
	for(int i = 60; i>=0; i--) if(lf & (1LL << i)) {
		fn.push_back(i * 1000);
	}
	cout << fn.size() << '\n';
	for(int x: fn) cout << x << " ";
	cout << '\n';
	assert(fuzz(fn) == n);
}

signed main() {
	int t; cin >> t;
	while(t--) solve();
}

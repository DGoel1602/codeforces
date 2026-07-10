#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n, q; cin >> n >> q;
	vector<ll> nums(n);
	for(ll &x: nums) cin >> x;
	vector<ll> ones(n+1, 0), sum(n+1, 0);
	for(int i = 1; i<n+1; i++) {
		sum[i] = sum[i-1] + nums[i-1] - 1;
		ones[i] = ones[i-1];
		if(nums[i-1] == 1) ones[i]++;
	}
	for(int i = 0; i<q; i++) {
		int l, r; cin >> l >> r;
		if(r == l) {
			cout << "NO\n";
			continue;
		}
		l--; r--;
		if(sum[r+1] - sum[l] >= ones[r+1] - ones[l]) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

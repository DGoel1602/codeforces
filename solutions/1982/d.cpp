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

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vvi grid(n, vi(m, 0));
	for(auto &vec: grid) for(auto &x: vec) cin >> x;
	vector<string> type(n);
	for(string &x: type) cin >> x;
	vvi pref(n+1, vi(m+1, 0));
	int diff = 0;
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=m; j++) {
			pref[i][j] =  - pref[i-1][j-1] + pref[i-1][j] + pref[i][j-1] + 
				(type[i-1][j-1] == '1' ? 1 : -1);
			diff += grid[i-1][j-1] * (type[i-1][j-1] == '1' ? 1 : -1);
		}
	

	vector<int> nums;
	for(int i = 0; i<=n-k; i++) {
		for(int j = 0; j<=m-k; j++) {
			int res =
					abs(pref[i+k][j+k] - 
					pref[i][j+k] - 
					pref[i+k][j] +
					pref[i][j]);
			if(res) nums.push_back(res);
		}
	}
	if(nums.empty()) return void(cout << (diff ? "No\n" : "Yes\n"));
	int cur = nums[0];
	for(int i = 1; i<sz(nums); i++) cur = __gcd(cur, nums[i]);
	cout << (abs(diff) % cur == 0 ? "Yes\n" : "No\n");
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

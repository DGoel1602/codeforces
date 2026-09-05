#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;
	int gc = a[0];
	rep(i, 1, n) gc = __gcd(gc, a[i]);

	vvi dp(n, vi(5001, -1));
	auto go = [&](int i, int cur, auto&& go) -> int {
		if(i == n) {
			if(cur == gc) return 0;
			return 1e9;
		}
		auto &ref = dp[i][cur];
		if(ref != -1) return ref;
		return ref = min(go(i+1, cur, go), 
				1 + go(i+1, cur == 0 ? a[i] : __gcd(a[i], cur), go));
	};
	int opt = go(0, 0, go) - 1;
	vi freq(5001);
	for(int x: a) freq[x]++;
	if(freq[gc]) cout << n - freq[gc] << '\n';
	else cout << opt + n - 1 << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

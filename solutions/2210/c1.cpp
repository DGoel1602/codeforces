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
	int n; cin >> n;
	vi a(n), b(n);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;

	int res = 0;
	for(int i = 0; i<n; i++) {
		int f = (i > 0 ? __gcd(a[i-1], a[i]) : 1);
		int s = (i < n-1 ? __gcd(a[i+1], a[i]) : 1);
		int lcm = f * s / __gcd(f, s);
		res += lcm < a[i];
	}
	cout << res << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

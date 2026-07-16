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
	int c; cin >> c;
	vi a(n);
	for(int &x: a) cin >> x;
	sort(all(a));
	int l = 0, r = n-1;
	int res = 0;
	while(l < r) {
		if(a[l] < c) {
			res += a[r] - c;
		} else {
			res += a[r] + a[l] - 2 * c;
		}
		l++;
		r--;
	}
	if(l == r) res += a[l] - c;
	cout << res << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

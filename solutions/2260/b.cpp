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
	int x, y, k; cin >> x >> y >> k;
	int res = 0, ls = 0;
	for(int i = 0; i<min(y+1, k); i++) {
		ls = (y + i) % (x + i);
		res += ls;
	}
	res += ls * (k - min(k, y + 1));
	cout << res << '\n';
}

void solve2() {
	int x, y, k; cin >> x >> y >> k;
	int res = 0;
	rep(i, 0, k) res += (y + i) % (x + i), cout << res << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

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
	while(k) {
		int nx = y - (x % y);
		if(k < nx) return void(cout << x + k << '\n');
		k -= nx;
		int ls = x;
		x += nx;
		while(x % y == 0) x /= y;
		if(x == ls) {
			return void(cout << x + k % nx << '\n');
		}
	}
	cout << x << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

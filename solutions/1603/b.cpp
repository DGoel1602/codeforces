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
	int x, y; cin >> x >> y;
	if(y < x) return void(cout << x + y << '\n');
	if(y % x == 0) return void(cout << x << '\n');
	return void(cout << y - (y % x) / 2 << '\n');
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

// n % x == y % n
// n % x = a
// n - cx = a
// y - dn = a
//
// (a + b) % a = b % a
// b % (a + b) = b
//
// 20 22
//

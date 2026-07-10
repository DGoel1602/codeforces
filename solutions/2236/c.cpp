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
	int a, b, x; cin >> a >> b >> x;
	int best = abs(a - b);
	int c = 0;
	while(a || b) {
		c++;
		if(a > b) a /= x;
		else b /= x;
		best = min(best, c + abs(a - b));
	}
	cout << best << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

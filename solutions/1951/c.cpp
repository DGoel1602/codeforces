#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vi a(n);
	for(int &x: a) cin >> x;

	int days = (k + m - 1) / m;
	vector<pii> sor;
	rep(i, 0, n) sor.push_back({a[i], i});
	sort(all(sor));

	vector<int> sor2;
	for(int d = 0; d<days; d++) {
		sor2.push_back(sor[d].second);
	}

	int ot = sor2[sor2.size()-1];
	sort(all(sor2));
	int bought = 0, ex = k % m;
	int cost = 0;
	for(int i: sor2) {
		if(i == ot && ex > 0) {
			cost += ex * (a[i] + bought);
			bought += ex;
		} else {
			cost += m * (a[i] + bought);
			bought += m;
		}
	}
	cout << cost << "\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

// 15 + 3
// 8 * 3 = 24
// 11 * 3 = 33
// 33 + 24 + 15 =

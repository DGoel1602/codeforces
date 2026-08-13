#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
	int n, m; cin >> n >> m;
	vector<pii> a(n);
	for(auto &[b, c]: a) cin >> b;
	for(auto &[b, c]: a) cin >> c;
	sort(all(a));
	int be = 0;
	rep(i, 0, n) {
		int mx = m / a[i].first;
		be = max(be, a[i].first * min(mx, a[i].second));
	}
	rep(i, 0, n - 1) {
		if(a[i+1].first != a[i].first + 1) continue;
		int lo = 0, hi = a[i].second + a[i+1].second;
		while(lo != hi) {
			int mid = lo + (hi - lo + 1) / 2;
			int cur = mid * a[i].first;
			if(mid > a[i].second) cur += mid - a[i].second;
			if(cur <= m) lo = mid;
			else hi = mid - 1;
		}

		int lf = m - a[i].first * lo;
		int conv = min({lo, lf, a[i+1].second});
		be = max(be, a[i].first * lo + conv);
	}
	cout << be << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

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
	int n, k; cin >> n >> k;
	vi a(n), b(n);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;
	rep(i, 0, n) if(b[i] < a[i]) swap(b[i], a[i]);
	vector<pii> ps;
	rep(i, 0, n) ps.push_back({a[i], b[i]});
	sort(all(ps));
	ll be = 1e18;
	rep(i, 0, n-1) {
		ll cur = ps[i].second - ps[i].first + ps[i+1].second - ps[i+1].first;
		ll nx =  - ps[i].second - ps[i].first + ps[i+1].second + ps[i+1].first;
		be = min(be, max(0LL, nx - cur));
	}
	ll res = be;
	rep(i, 0, n) res += (ll)b[i] - a[i];
	cout << res << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

// a  c
// b  d
//
// a  b   a <-> c
// c  d   b <-> d
//
// a  b   a <-> d
// d  c   b <-> c

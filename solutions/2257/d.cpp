#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int s, q; cin >> s >> q;
	vector<pii> recs;
	recs.push_back({0, 1e15});
	for(int i = 1; i * i <= s; i++) {
		if(s % i == 0) {
			recs.emplace_back(i, s / i);
			if(s / i != i) recs.emplace_back(s / i, i);
		}
	}
	sort(all(recs));
	set<pii> mp;
	for(auto [x, y]: recs) mp.insert({y, x});
	vi xs;
	for(auto [x, _]: recs) xs.push_back(x);
	vi pref(recs.size() + 1);
	int ls = 0;
	rep(i, 1, sz(recs) + 1) {
		pref[i] = pref[i-1] + ((recs[i-1].first - ls) * recs[i-1].second);
		ls = recs[i-1].first;
	}
	while(q--) {
		int x, y; cin >> x >> y;
		pii cls = *mp.lower_bound({y, 0});
		int res = min(cls.second, x) * y;
		if(cls.second < x) {
			int st = lower_bound(all(xs), cls.second) - xs.begin() + 1;
			int end = lower_bound(all(xs), x) - xs.begin() - 1 + 1;
			int total = pref[end] - pref[st];
			int fx = recs[end - 1].first;
			int fy = (end) < sz(recs) ? recs[end].second : 0;
			res += total + (x - fx) * fy;
		}
		cout << res << '\n';
	}
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

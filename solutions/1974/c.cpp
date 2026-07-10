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
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;

	vi cp(a);
	sort(all(cp));
	cp.erase(unique(all(cp)), cp.end());
	for(int &x: a) x = lower_bound(all(cp), x) - cp.begin();

	auto cnt = [&](int one, int two) -> ll {
		vector<map<pii, int>> cnts(n+1);
		rep(i, 0, n) {
			int first = i + one, second = i + two;
			if(first < 0 || first >= n || second < 0 || second >= n) continue;
			cnts[a[i]][{a[first], a[second]}]++;
		}

		ll res = 0;
		map<pair<int, int>, int> nmp;

		for(auto mp: cnts) {
			for(auto [el, c]: mp) {
				auto [f, s] = el;
				res += c * nmp[{f, s}];
				nmp[{f, s}] += c;
			}
		}
		return res;
	};

	cout << cnt(1, 2) + cnt(-1, 1) + cnt(-2, -1) << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

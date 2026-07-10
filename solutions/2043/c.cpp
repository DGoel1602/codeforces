#include <bits/stdc++.h>
#include <cstring>
#include <string>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

pii mima(int n, vi &a) {
	int mx = 0;
	int cur = 0;
	for(int x: a) {
		cur = max(cur + x, 0);
		mx = max(mx, cur);
	}

	int mi = 0;
	cur = 0;
	for(int x: a) {
		cur = min(cur + x, 0);
		mi = min(mi, cur);
	}

	return {mi, mx};
}

void solve() {
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;
	bool f = false;
	vi pref, suf;
	int ex = 0;
	for(int x: a) {
		if(x != -1 && x != 1) {
			ex = x;
			f = true;
			continue;
		}
		if(f) suf.push_back(x);
		else pref.push_back(x);
	}

	reverse(all(pref));
	pii prefpos = mima(pref.size(), pref);
	pii sufpos = mima(suf.size(), suf);

	vi res;
	for(int i = prefpos.first; i<=prefpos.second; i++) res.push_back(i);
	for(int i = sufpos.first; i<=sufpos.second; i++) res.push_back(i);

	pii bef = {0, 0}, aft = {0,0};

	int cur = 0;
	for(int i = 0; i<suf.size(); i++) cur += suf[i], aft.first = min(aft.first, cur), aft.second = max(aft.second, cur);
	cur = 0;
	for(int i = 0; i<pref.size(); i++) cur += pref[i], bef.first = min(bef.first, cur), bef.second = max(bef.second, cur);

	for(int i = bef.first+aft.first; i<=bef.second+aft.second; i++) res.push_back(i + ex);

	sort(all(res));
	res.erase(unique(all(res)), res.end());
	cout << res.size() << "\n";
	for(int x: res) cout << x << " ";
	cout << "\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

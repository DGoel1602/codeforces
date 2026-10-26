#include <algorithm>
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
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;

	vector<int> fs, ss;
	int cf = 0, cs = 0;
	int ls = -1;
	for(int i = 0; i<n; i++) {
		cf += s[i] == 'W';
		if(s[i] == 'W') {
			if(ls != -1) fs.push_back(i - ls - 1);
			ls = i;
		}
	}
	ls = -1;
	for(int i = 0; i<m; i++) {
		cs += t[i] == 'W';
		if(t[i] == 'W') {
			if(ls != -1) ss.push_back(i - ls - 1);
			ls = i;
		}
	}
	sort(all(fs));
	sort(all(ss));

	vi preffs = {0}, prefss = {0};
	for(int x: fs) preffs.push_back(preffs.back() + x);
	for(int x: ss) prefss.push_back(prefss.back() + x);

	int lastsf = -1, lastss = -1;
	for(int i = n-1; i>=0; i--) {
		if(s[i] == 'W') {
			lastsf = i;
			break;
		}
	}
	for(int i = m-1; i>=0; i--) {
		if(t[i] == 'W') {
			lastss = i;
			break;
		}
	}

	int lsw = -1;
	for(int i = 0; i<n; i++) {
		char c = s[i];
		if(c == 'W') lsw = i;
		if(c == 'W') continue;
		if(lsw != -1) {
			int mn = lsw;
			int mx = max(lsw + m, cs ? lastss + i : 0);
			cout << mx - mn + 1 << ' ';
		}
		else if(cs == 0) cout << "1 ";
		else {
			int idx = upper_bound(all(ss), i) - ss.begin();
			cout << ss.size() + prefss[idx] + (cs - idx) * i + 2 << ' ';
		}
	}
	cout << '\n';

	lsw = -1;
	for(int i = 0; i<m; i++) {
		char c = t[i];
		if(c == 'W') lsw = i;
		if(c == 'W') continue;
		if(lsw != -1) {
			int mn = lsw;
			int mx = max(lsw + n, cf ? lastsf + i : 0);
			cout << mx - mn + 1 << ' ';
		}
		else if(cf == 0) cout << "1 ";
		else {
			int idx = upper_bound(all(fs), i) - fs.begin();
			cout << fs.size() + preffs[idx] + (cf - idx) * i + 2 << ' ';
		}
	}
	cout << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	vi nxs(n, -1);
	int idx = n-1;
	for(int i = n-2; i>=0; i--) {
		nxs[i] = idx;
		if(s[idx] <= s[i]) idx = i;
	}

	int cur = idx;
	vector<int> path;
	string lgs;
	int lf = 0;
	char start = s[idx];

	while(idx != -1) {
		path.push_back(idx);
		lgs += s[idx];
		if(s[idx] == start) lf++;
		idx = nxs[idx];
	}

	sort(all(lgs));
	for(int i = 0; i<path.size(); i++) {
		s[path[i]] = lgs[i];
	}

	string cp(s);
	sort(all(cp));
	cout << (cp == s ? ((int)lgs.size()-lf) : -1) << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

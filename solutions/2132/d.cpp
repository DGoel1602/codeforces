#include <bits/stdc++.h>
#include <cstring>
#include <string>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

int digits(int n) {
	int nd = to_string(n).size();
	int c = 1;
	rep(i, 0, nd - 1) c *= 10; 
	int ex = (n - c) * nd;

	int cur = 0;
	int bel = 0;
	int base = 1;
	rep(i, 0, nd - 1) {
		bel++;
		cur += 9 * bel * base;
		base *= 10;
	}
	return cur + ex;
}

string s;
pii dp[20][2];

pair<int, int> go(int i, bool tight) {
	if(i == s.size()) return {1, 0};
	if(dp[i][tight].first != -1) return dp[i][tight];

	int res = 0;
	int cnt = 0;
	for(int j = 0; j<=9; j++) {
		if(tight && j > s[i] - '0') break;
		pii r = go(i+1, tight && j == s[i] - '0');
		res += r.second + j * r.first;
		cnt += r.first;
	}
	return dp[i][tight] = {cnt, res};
}

void solve() {
	int k; cin >> k;
	int lsn = 0;
	int lo = 1, hi = 1e14;
	while(lo != hi) {
		int m = lo + (hi - lo + 1) / 2;
		if(digits(m) >= k) hi = m - 1;
		else lo = m;
	}
	lsn = lo;
	s = to_string(lsn-1);
	memset(dp, -1, sizeof(dp));
	int res = go(0, true).second;
	int ex = k - digits(lsn);
	string st = to_string(lsn);
	rep(i, 0, ex) res += st[i] - '0';
	cout << res << "\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

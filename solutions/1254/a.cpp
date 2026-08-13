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
	int n, m, k; cin >> n >> m >> k;

	vector<string> grid(n);
	for(string &x: grid) cin >> x;
	string g(n*m, '.'), res(n*m, '.');

	int l = 0;
	rep(i, 0, n) {
		if(i % 2 == 0) rep(j, 0, m) g[l] = grid[i][j], l++;
		else for(int j = m-1; j>=0; j--) g[l] = grid[i][j], l++;
	}

	string th = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int cur = 0;
	int cnt = 0;
	for(char c: g) cnt += c == 'R';
	rep(i, 0, k) {
		int ts = cnt / (k - i);
		int c = 0;
		int ls_cur = cur;
		while(c < ts) {
			if(g[cur] == 'R') c++;
			cur++;
		}
		cnt -= ts;
		for(; ls_cur <= cur; ls_cur++) res[ls_cur] = th[i];
	}

	int ls = 'a';
	rep(i, 0, n*m) {
		if(res[i] != '.') ls = res[i];
		else res[i] = ls;
	}

	vector<string> res2(n, string(m, '.'));
	l = 0;
	rep(i, 0, n) {
		if(i % 2 == 0) rep(j, 0, m) res2[i][j] = res[l], l++;
		else for(int j = m-1; j>=0; j--) res2[i][j] = res[l], l++;
	}
	for(string x: res2) cout << x << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
	int n, q; cin >> n >> q;
	vi a(n);
	for(int &x: a) cin >> x;
	vi cp(a);
	sort(all(cp));
	map<int, vector<int>> idxs;
	for(int i = n-1; i>=0; i--) idxs[a[i]].push_back(i);
	vi got(n);
	rep(i, 0, n) {
		int idx = idxs[cp[i]].back();
		idxs[cp[i]].pop_back();
		got[i] = idx;
	}
	int mx = 0;
	rep(i, 0, n) {
		int xo = i ^ got[i];
		if(!xo) continue;
		int hb = 31 - __builtin_clz(xo);
		mx = max(mx, 1 << hb);
	}
	cout << mx << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

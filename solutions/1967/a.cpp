#include <bits/stdc++.h>
#include <numeric>
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
	vi a(n);
	for(int &x: a) cin >> x;
	sort(all(a));
	int lo = 0, hi = 3e12;
	while(lo != hi) {
		int m = lo + (hi - lo + 1) / 2;
		int lf = k;
		vi cp(a);
		rep(i, 0, n)
			if(cp[i] < m) lf -= m - cp[i], cp[i] = m;
		if(lf < 0) hi = m - 1;
		else lo = m;
	}
	rep(i, 0, n)
		if(a[i] < lo) k -= lo - a[i], a[i] = lo;
	rep(i, 0, k) a[i]++;
	sort(all(a));
	int tc = a[0] * n;
	int d = 1;
	for(; d<n; d++) if(a[d] != a[d-1]) break;
	tc += n - d;
	cout << tc - n + 1 << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

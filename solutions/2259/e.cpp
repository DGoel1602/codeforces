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
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;
	rep(i, 0, n-1) if(abs(a[i+1] - a[i]) > 1 && a[i+1] != -1 && a[i] != -1) return void(cout << "-1\n");

	vi firsts(n);

	vi diffs(n);
	rep(i, 0, n) if(a[i] > 0) {
		diffs[max(0LL, i - a[i] + 1)]++;
		if(i + a[i] < n) diffs[i + a[i]]--;
	}
	int cur = 0;
	vi b;
	vi blocked(n);
	rep(i, 0, n) {
		cur += diffs[i];
		if(cur && !a[i]) return void(cout << "-1\n");
		blocked[i] = cur != 0;
	}

	auto can = [&](int j) {
		return j >= 0 && j < n && !blocked[j];
	};

	rep(i, 0, n) if(a[i] > 0) {
		int lf = i - a[i], ri = i + a[i];
		bool l = can(lf), r = can(ri);
		if(!l && !r) return void(cout << "-1\n");
	}

	rep(i, 0, n) cout << (!blocked[i] || a[i] == 0);
	cout << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

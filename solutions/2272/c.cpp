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
	int n, x; cin >> n >> x;
	vi a(n);
	for(int &x: a) cin >> x;

	auto works = [&](int k) -> bool {
		int lf = x, pnd = -1;
		for(int i = 0; i<n; i++) {
			if(i && a[i] - a[i-1] <= k) continue;
			if(i < (n-1) && a[i+1] - a[i] <= k) continue;
			if(pnd != -1 && a[i] - a[pnd] <= 2 * k) pnd = -1;
			else pnd = i, lf--;
		}

		return lf >= 0;
	};

	int lo = 1, hi = 1e9;
	while(lo != hi) {
		int m = lo + (hi - lo) / 2;
		if(!works(m)) lo = m + 1;
		else hi = m;
	}
	cout << lo << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

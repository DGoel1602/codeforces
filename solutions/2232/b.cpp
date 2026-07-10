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
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;

	cout << a[0] << " ";
	int prev = a[0];
	int sum = a[0];
	for(int i = 1; i<n; i++) {
		if(a[i] > prev) {
			cout << prev << " ";
			sum += a[i];
			continue;
		}

		int lo = a[i], hi = prev;
		while(lo != hi) {
			int mid = lo + (hi-lo+1)/2;
			int excess = sum - (mid * i);
			if(excess < mid - a[i]) hi = mid - 1;
			else lo = mid;
		}
		cout << lo << " ";
		sum += a[i];
		prev = lo;
	}
	cout << "\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

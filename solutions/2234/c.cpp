#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
	vi a(n);
	for(int &x: a) cin >> x;
	for(int i = 0; i<n; i++) {
		vi res(n, 1e9);
		res[0] = 0;
		int cur = a[n-1];
		for(int j = n-1; j>=1; j--) {
			if(a[j] > cur) cur = a[j];
			res[j] = cur;
		}

		vi res2(n, 0);
		for(int j = 1; j<n; j++) {
			res2[j] = max(res2[j-1], a[j-1]);
			res[j] = min(res[j], res2[j]);
		}

		cout << accumulate(all(res), 0LL) << " ";
		rotate(a.begin(), a.begin() + 1, a.end());
	}
	cout << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

// 1 2 3 4
// 0 1 2 3

// 4 1 2 3
// 0 3 3 3

// 5 2 5 3 1
// 0 5 5 3 1

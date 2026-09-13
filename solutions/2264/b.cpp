#include <bits/stdc++.h>
#include <queue>
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
	vi a(n);
	for(int &x: a) cin >> x;
	int sum = 0;
	priority_queue<int> pq;
	for(int i = 0; i<m-1; i++) sum += a[i], pq.push(a[i]);
	int best = -2e18;
	for(int i = m-1; i<n; i++) {
		best = max(best, -sum + m * a[i]);
		sum += a[i];
		pq.push(a[i]);
		while(pq.size() > m-1) {
			int t = pq.top(); pq.pop();
			sum -= t;
		}
	}
	cout << best << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

// 1 + 2 + 2 - 1 - 1 + 3 + 3 + 3 - 2 - 2 - 2
// -1 -2 +3

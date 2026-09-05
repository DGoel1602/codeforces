#include <algorithm>
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
	int n, m; cin >> n >> m;
	vi a(n);
	for(int &x: a) cin >> x;
	sort(all(a));
	int best = 0;
	vi freq(2*m+1);
	for(int x: a) freq[x]++;
	for(int i = 1; i<=m; i++) {
		int res = n - (lower_bound(all(a), i) - a.begin()) + freq[2*i];
		best = max(best, res);
	}
	cout << best << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

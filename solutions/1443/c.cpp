#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	vector<pair<ll, ll>> vals(n);
	for(auto &[a, b]: vals) cin >> a;
	for(auto &[a, b]: vals) cin >> b;
	sort(all(vals));
	ll be = 1e18;
	ll sum = 0;
	for(int i = n-1; i>=0; i--) {
		be = min(be, max(sum, vals[i].first));
		sum += vals[i].second;
	}
	be = min(be, sum);
	cout << be << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

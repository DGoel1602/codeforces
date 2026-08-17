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
	int n; cin >> n;
	vi a(n), b(n);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;
	vi pref(n), suf(n);
	rep(i, 1, n) pref[i] = pref[i-1] + b[i-1];
	for(int i = n-2; i>=0; i--) suf[i] = suf[i+1] + a[i+1];
	int best = 1e9;
	rep(i, 0, n) best = min(max(pref[i], suf[i]), best);
	cout << best << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

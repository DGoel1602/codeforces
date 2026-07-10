#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n, q; cin >> n >> q;
	vi a(n), b(n);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;
	rep(i, 0, n) a[i] = max(a[i], b[i]);
	vi res(n);
	int mx = 0;
	for(int i = n-1; i>=0; i--) {
		mx = max(mx, a[i]);
		res[i] = mx;
	}
	vi pref(n+1, 0);
	for(int i = 1; i<=n; i++) pref[i] = pref[i-1] + res[i-1];
	while(q--) {
		int l, r; cin >> l >> r;
		cout << pref[r] - pref[l-1] << " ";
	}
	cout <<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

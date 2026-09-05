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
	int n, q; cin >> n >> q;
	vi a(n);
	for(int &x: a) cin >> x;
	vi pref(n+1);
	for(int i = 1; i<=n; i++) pref[i] = pref[i-1] + __lg(a[i-1]);
	vi pref_2s(n+1);
	for(int i = 1; i<=n; i++) pref_2s[i] = pref_2s[i-1] + (__builtin_popcount(a[i-1]) == 1);
	vi pref_1s(n+1);
	for(int i = 1; i<=n; i++) pref_1s[i] = pref_1s[i-1] + 
		(__builtin_popcount(a[i-1]) == 2 && (a[i-1] & 1));
	while(q--) {
		int l, r; cin >> l >> r;
		--l;
		int res = 
			r - l + pref[r] - pref[l] - (pref_2s[r] - pref_2s[l]) - ((pref_1s[r] - pref_1s[l] + 1) / 2);
		cout << res << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

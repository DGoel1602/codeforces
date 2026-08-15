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
	vi a(n), b(n);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;

	vi c(n);
	rep(i, 0, n) c[i] = (a[i] * b[i])/__gcd(a[i], b[i]);
	vi pref(c), suf(c);
	rep(i, 1, n) pref[i] = __gcd(pref[i], pref[i-1]);
	for(int i = n-2; i>=0; i--) suf[i] = __gcd(suf[i], suf[i+1]);
	cout << (a == pref && b == suf ? "YES\n" : "NO\n");
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

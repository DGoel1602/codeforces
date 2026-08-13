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
	bool h_1 = false;
	vi a(n);
	rep(i, 0, n) {
		cin >> a[i];
		h_1 |= a[i] == 1;
	}
	sort(all(a));
	bool b = false;
	rep(i, 0, n)
		b |= a[i] == 0 || a[i] == 2 || (i < n - 1 && a[i+1] == a[i]+1);
	cout << (h_1 && b ? "NO\n" : "YES\n");

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

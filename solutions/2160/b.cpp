#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	vi b(n); 
	for(int &x: b) cin >> x;
	vi a(n);

	int cur = 1;
	int ls = 0;
	for(int i = 0; i<n; i++) {
		int diff = b[i] - ls;
		if(diff == i + 1) a[i] = cur++;
		else a[i] = a[i-diff];
		ls = b[i];
	}
	for(int x: a) cout << x << " ";
	cout << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

#include <algorithm>
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
	vi a(n);
	for(int &x: a) cin >> x;
	int oidx = -1, nidx = -1;
	rep(i, 0, n) {
		if(a[i] == 1) oidx = i + 1;
		if(a[i] == n) nidx = i + 1;
	}
	if(oidx == -1) {
		cout << "? 1 2" << endl;
		int r; cin >> r;
		if(r == 0) cout << "! A" << endl;
		else cout << "! B" << endl;
		return;
	} else if(nidx == -1) {
		cout << "? " << n << " 2" << endl;
		int r; cin >> r;
		if(r == 0) cout << "! A" << endl;
		else cout << "! B" << endl;
		return;
	}

	cout << "? " << oidx << " " << nidx << endl;
	int r; cin >> r;
	if(r < n - 1) return void(cout << "! A" << endl);
	cout << "? " << nidx << " " << oidx << endl;
  cin >> r;
	if(r < n - 1) return void(cout << "! A" << endl);

	cout << "! B" << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

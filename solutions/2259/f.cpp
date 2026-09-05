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

struct FT {
	vi a;
	int n;
	FT(int n): n(n), a(n+1) {};
	void update(int i, int x) {
		for(int pos = ++i; pos <= n; pos += pos & (-pos)) a[pos] += x;
	}
	int query(int r) {
		int sum = 0;
		for(int i = ++r; i > 0; i -= i & (-i)) sum += a[i];
		return sum;
	}
};

void solve() {
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;
	string s; cin >> s;
	
	vector<FT> fts(2, n);
	int cur = 0;
	rep(i, 0, n) {
		fts[a[i]].update(i, 1);
		if(!a[i]) cur += fts[1].query(i);
	}

	int lf = -1, ri = n;

	for(int i = 0; i<n; i++) {
		cout << cur << ' ';
		if(s[i] == '1') {
			++lf;
			while(lf < n && a[lf] == 0) lf++;
			if(lf < n) cur -= fts[0].query(n-1) - fts[0].query(lf), fts[1].update(lf, -1);
		} else {
			ri--;
			while(ri >= 0 && a[ri] == 1) ri--;
			if(ri >= 0) cur -= fts[1].query(ri), fts[0].update(ri, -1);
		}
	}
	cout << cur << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

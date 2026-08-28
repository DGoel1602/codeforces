#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n, m; cin >> n >> m;

	vi a(n), b(m);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;
	n++; m++;
	a.push_back(1);
	b.push_back(1);

	int p1 = 0, p2 = 0;
	for(; p1 < n-1 && p2 < m-1;) {
		int r1 = a[p1] - (a[p1+1] - 1);
		int r2 = b[p2] - (b[p2+1] - 1);
		if(r1 > r2) {
			p2++;
			a[p1] -= r2;
		} else if(r1 < r2) {
			p1++;
			b[p2] -= r1;
		} else p1++, p2++;
	}
	if(p2 == m-1) return void(cout << "1\n");
	cout << "2\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

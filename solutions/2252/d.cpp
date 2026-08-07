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
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	vi d;
	for(int i = 0; i<n-1; i++)
		d.push_back(a[i+1]-a[i]);
	for(int l = 0; l<n-1; l++) {
		int r = l+1;
		while(r<n-1 && (d[r] % 2 != 0) == (d[l]%2 != 0)) r++;
		sort(d.begin() + l, d.begin() + r);
		l = r-1;
	}
	int c = a[0];
	for(int x: d) cout << c << " ", c += x;
	cout << c << " ";
	cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}


// 1 2 3 4
//
// 1, 2, 2 + 4 - 3, 4
// 1, 1 + 4 - 3, 2 + 4 - 3, 4
// 1, 1 + 4 - 3, 1 + 4 - 2
//
// 1, 1 + 3 - 2, 3, 4
// 1, 1 + 3 - 2, 1 - 2 + 4, 4
// 1, 1 + 1 - 2 + 4 - 1 - 3 + 2, 1 - 2 + 4, 4
// 1, 1 + 4 - 3, 1 - 2 + 4, 4
//
// 1, 1 + 4 - 3, 1 - 2 + 4, 4, 5
// 1, 1 + 4 - 3, 1 - 2 + 4, 1 + 5 - 2, 5
// 1, 1 + 4 - 3, 1 + 5 - 3, 1 + 5 - 2, 5
//
// 100, 1 + 5 - 4, 1 + 3 - 2, 2 + 4 - 3, 120
// 5, 1 + 4 - 3, 1 + 5 - 3,

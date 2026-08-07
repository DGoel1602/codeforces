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
	int n, m, x, y; cin >> n >> m >> x >> y;
	vi a(x), b(y);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;

	auto go = [&](int n, int m) -> int {
		set<int> s;
		for(int i = x-1; i>=0 && s.size() < n; i--) s.insert(a[i]);
		for(int i = y-1; i>=0 && s.size() < n+m; i--) s.insert(b[i]);
		for(int i = x-1; i>=0 && s.size() < n+m; i--) s.insert(a[i]);
		int sum = 0;
		for(int x: s) sum += x;
		s.clear();
		for(int i = y-1; i>=0 && s.size() < m; i--) s.insert(b[i]);
		for(int i = x-1; i>=0 && s.size() < n+m; i--) s.insert(a[i]);
		for(int i = y-1; i>=0 && s.size() < n+m; i--) s.insert(b[i]);
		int sum2 = 0;
		for(int x: s) sum2 += x;
		return max(sum, sum2);
	};

	if(x >= n && y >= m)
		return void(cout << max(go(n-1, m), go(n, m-1)) << '\n');
	if(x >= n) return void(cout << go(n, y) << '\n');
	if(y >= m) return void(cout << go(x, m) << '\n');
	cout << go(x, y) << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

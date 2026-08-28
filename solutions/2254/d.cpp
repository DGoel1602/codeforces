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
	vi a(n);
	for(int &x: a) cin >> x;
	vi b(a);
	sort(all(b));
	int cnt = 0;
	if(b[0] != 0) return void(cout << "-1\n");
	int ls = 0;
	map<int, int> mp;
	rep(i, 0, n) {
		if(i > 0 && b[i-1] != b[i]) {
			int diff = b[i] - b[i-1];
			if(diff % cnt != 0 || diff / cnt <= ls) return void(cout << "-1\n");
			mp[b[i-1]] = diff / cnt;
			ls = diff / cnt;
			cnt = 1;
		} else cnt++;
	}

	mp[b.back()] = ++ls;
	for(int x: a) cout << mp[x] << " ";
	cout << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

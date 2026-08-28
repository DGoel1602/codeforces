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
	multiset<int> s;
	rep(i, 0, n) {
		int x; cin >> x;
		s.insert(x);
	}
	int cur = 0;
	vi res;
	rep(i, 0, n) {
		int mn = 1 - cur;
		auto it = s.lower_bound(mn);
		if(it == s.end()) return void(cout << "-1\n");
		cur += *it;
		s.erase(it);
		res.push_back(cur);
	}
	for(int x: res) cout << x << " ";
	cout << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

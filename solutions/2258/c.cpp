#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<array<int, 3>, int> mp;

int query(int n, int u, int v, int d) {
	if(d >= n) return 0;
	if(u == v) return d == 0;
	if(u > v) swap(u, v);
	if(mp.count({u, v, d})) return mp[{u, v, d}];
	cout << "? " << u << " " << v << " " << d << endl;
	int res; cin >> res;
	return mp[{u, v, d}] = res;
}

pii find_far(int n, int td, int cur = 0, int ot = -1) {
	if(ot == -1) ot = td;

	vi ord(n);
	iota(all(ord), 1);
	shuffle(all(ord), rng);

	for(int i: ord) {
		while(query(n, td, i, cur+1)) cur++, ot = i;
	}
	return {cur, ot};
}

void solve() {
	int n; cin >> n;
	mp.clear();

	auto [d, one] = find_far(n, 1);
	auto [d2, two] = find_far(n, one, d, 1);
	cout << "! " << one << " " << two << " " << d2 << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

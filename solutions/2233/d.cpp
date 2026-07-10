#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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

	auto attempt = [&](int u, int v) -> bool {
		if(u < 0 || v < 0 || u >= n || v >= n) return false;
		if(u != v && a[u] == a[v]) return false;
		swap(a[u], a[v]);
		vi cp(a);
		cp.erase(unique(all(cp)), cp.end());
		vector<bool> seen(n);
		for(int x: cp) {
			if(seen[x]) {
				swap(a[u], a[v]);
				return false;
			}
			seen[x] = 1;
		}
		swap(a[u], a[v]);
		return true;
	};

	vi cp(a);
	sort(all(cp));
	cp.erase(unique(all(cp)), cp.end());
	rep(i, 0, n) a[i] = lower_bound(all(cp), a[i]) - cp.begin();

	if(attempt(0, 0)) return void(cout << "YES\n");

	vvi indices(n);
	rep(i, 0, n) indices[a[i]].push_back(i);
	vector<vector<pair<int, int>>> segs(n);
	vector<pair<int, int>> allsegs;
	rep(i, 0, n) {
		auto nx = upper_bound(all(indices[a[i]]), i) - indices[a[i]].begin();
		if(nx == sz(indices[a[i]])) continue;
		int idx = indices[a[i]][nx];
		if(idx != i+1) {
			allsegs.push_back({indices[a[i]].front(), i});
			allsegs.push_back({indices[a[i]].back(), i});
			allsegs.push_back({indices[a[i]].front(), idx});
			allsegs.push_back({indices[a[i]].back(), idx});
		}
	}
	if(allsegs.size() > 50) return void(cout << "NO\n");
	for(auto [a, b]: allsegs) {
		if(attempt(b, a-1) || attempt(b, a+1) || attempt(a, b+1) || attempt(a, b-1)) return void(cout << "YES\n");
	}
	cout << "NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

// 1 3 1 2 1 3
// 1 2 3 1 2
// 1 1 3 2 2
// 1 3 1 1 3 2
// 3 3 1 1 1 2
// ---- --
// 	 ------- 2
// 1 1 3 3 2 1
// 1 1 2 3 3 1
// 3 only acceptable if other length is exactly 2
// 2 only acceptable if only one guy inside you has a partner anywhere, sometimes not even that cause see above

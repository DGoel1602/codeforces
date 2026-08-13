#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

struct DSU {
	int n;
	vi sz, p;
	DSU(int n): n(n), sz(n, 1), p(n) {
		iota(all(p), 0);
	}
	int find(int x) {
		if(p[x] != x) return p[x] = find(p[x]);
		return p[x];
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if(a == b) return false;
		if(sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		p[b] = a;
		return true;
	}
};

void solve() {
	int n, m; cin >> n >> m;
	DSU dsu(n);
	rep(i, 0, m) {
		int k; cin >> k;
		if(!k) continue;
		int f; cin >> f;
		rep(i, 0, k-1) {
			int x; cin >> x;
			dsu.join(f-1, x-1);
		}
	}
	rep(i, 0, n) cout << dsu.sz[dsu.find(i)] << ' ';
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while(t--) solve();
}

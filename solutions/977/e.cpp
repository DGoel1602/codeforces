#include <bits/stdc++.h>
#include <numeric>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

struct DSU {
	int n;
	vi sz, p, cnt;
	DSU(int n): n(n), cnt(n, 0), sz(n, 1), p(n) {
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
	vi cnt(n);
	rep(i, 0, m) {
		int u, v; cin >> u >> v;
		--u; --v;
		cnt[u]++;
		cnt[v]++;
		dsu.join(u, v);
	}
	rep(i, 0, n) if(cnt[i] == 2) dsu.cnt[dsu.find(i)]++;
	int res = 0;
	rep(i, 0, n) if(dsu.p[i] == i && dsu.cnt[i] == dsu.sz[i]) res++;
	cout << res << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while(t--) solve();
}

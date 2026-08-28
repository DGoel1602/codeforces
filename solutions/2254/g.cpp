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
	vvi adj(n);
	for(int i = 1; i<n; i++) {
		int p; cin >> p;
		adj[--p].push_back(i);
	}
	auto dfs = [&](int u, auto&& dfs) -> multiset<int> {
		if(adj[u].size() == 0) return { a[u] };
		multiset<int> res = { a[u] };
		for(int v: adj[u]) {
			multiset<int> ch = dfs(v, dfs);
			if(ch.size() > res.size()) swap(ch, res);
			for(int x: ch) res.insert(x);
		}
		res.erase(res.begin());
		return res;
	};
	multiset<int> al({all(a)});
	multiset<int> res = dfs(0, dfs);
	int tot = 0;
	for(int x: res) tot += x, al.erase(al.lower_bound(x));
	rep(i, 0, res.size()-1) cout << "-1 ";
	cout << tot << ' ';
	while(al.size()) {
		tot += *prev(al.end());
		al.erase(prev(al.end()));
		cout << tot << " ";
	}
	cout << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

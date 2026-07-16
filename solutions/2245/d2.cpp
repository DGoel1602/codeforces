#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

struct TwoSat {
	int N;
	vector<basic_string<int>> gr;
	vi values;

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	vi v, comp, z; int time = 0;
	int dfs(int i) {
		int low = v[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, v[e] ?: dfs(e));
		if (low == v[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return v[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		v.assign(2*N, 0); comp = v;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

void solve() {
	int n, m; cin >> n >> m;
	map<pii, int> mp;
	rep(_, 0, m) {
		int o, i, j; cin >> o >> i >> j;
		--i; --j;
		mp[{i, j}] = o;
	}

	TwoSat ts(n);
	for(auto [ij, cor]: mp) {
		auto [i, j] = ij;
		if(i == j) {
			if(cor == 2) ts.setValue(i);
			else ts.setValue(~i);
			continue;
		}
		if(cor == 1) ts.either(~i, ~j);
		else ts.either(i, j);
	}
	if(!ts.solve()) return void(cout << "NO\n");
	vi &neg = ts.values;

	vvi adj(n);
	vi ind(n);
	for(auto [ij, cor]: mp) {
		auto [i, j] = ij;
		if(i == j) continue;
		if(cor == 1) {
			if(!neg[i] && neg[j]) adj[j].push_back(i), ind[i]++;
			if(neg[i] && !neg[j]) adj[i].push_back(j), ind[j]++;
		} else {
			if(neg[i] && !neg[j]) adj[j].push_back(i), ind[i]++;
			if(!neg[i] && neg[j]) adj[i].push_back(j), ind[j]++;
		}
	}

	queue<int> q;
	for(int i = 0; i<n; i++) if(!ind[i]) q.push(i);
	vi tops;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		tops.push_back(u);
		for(int v: adj[u]) {
			ind[v]--;
			if(!ind[v]) q.push(v);
		}
	}
	if(tops.size() != n) return void(cout << "NO\n");
	vi a(n);
	int cur = 1;
	for(int i: tops) {
		a[i] = (cur++) * (neg[i] ? -1 : 1);
	}
	cout << "YES\n";
	for(int x: a) cout << x << " ";
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int c, n;

struct RollbackUF {
	vector<int> e; vector<pair<int, int>> st; 
	RollbackUF(int n) : e(n, -1) {}
	int size(int x) { return -e[find(x)]; } //if no rollback
	int find(int x) { return e[x] < 0 ? x :/*e[x] =*/find(e[x]); }
	int time() { return st.size(); } 
	void rollback(int t) { 
		for (int i = time(); i --> t;)
			e[st[i].first] = st[i].second;
		st.resize(t);
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		st.push_back({a, e[a]});
		st.push_back({b, e[b]});
		e[a] += e[b]; e[b] = a;
		return true;
	}
	multiset<int> getSizes() {
		multiset<int> res;
		for(int i = 0; i<n; i++) if(find(i) == i) res.insert(size(i));
		return res;
	}
};

const ll mod = 998244353;
ll modpow(ll b, ll e) {
	ll res = 1;
	for(; e; b = (b * b) % mod, e /= 2)
		if(e & 1) res = (res * b) % mod;
	return res;
}

map<multiset<int>, ll> dp;

void solve() {
	int m; cin >> m;
	RollbackUF dsu(n);
	for(int i = 0; i<m; i++) {
		int u, v; cin >> u >> v;
		--u; --v;
		dsu.join(u, v);
	}
	ll inv = modpow(n*n, mod - 2);

	auto go = [&](auto&& go) -> ll {
		multiset<int> sizes = dsu.getSizes();
		if(sizes.size() == 1) return 0;
		if(dp.count(sizes)) return dp[sizes];
		auto &ref = dp[sizes];
		ref = 1;
		int selfs = 0;
		for(int i = 0; i<n; i++) {
			for(int j = 0; j<n; j++) {
				int ct = dsu.time();
				if(dsu.join(i, j)) {
					ref = (ref + inv * go(go)) % mod;
				} else selfs++;
				dsu.rollback(ct);
			}
		}
		ll one_minus_self_prob = ((n * n - selfs) * inv) % mod;
		ref = (ref * modpow(one_minus_self_prob, mod - 2)) % mod;
		return ref;
	};
	cout << go(go) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> n;
	while(c--) solve();
}

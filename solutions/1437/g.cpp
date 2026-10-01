#include <bits/stdc++.h>
#include <cassert>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define sz(x) (int)(x).size()
using vi = vector<int>;

struct AhoCorasick {
	enum {alpha = 26, first = 'a'}; // change this!
	struct Node {
		// (nmatches is optional)
		int back, next[alpha], start = -1, end = -1, nmatches = 0;
		Node(int v) { memset(next, v, sizeof(next)); }
	};
	vector<Node> N;
	vi backp;
	void insert(string& s, int j) {
		assert(!s.empty());
		int n = 0;
		for (char c : s) {
			int& m = N[n].next[c - first];
			if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
			else n = m;
		}
		if (N[n].end == -1) N[n].start = j;
		backp.push_back(N[n].end);
		N[n].end = j;
		N[n].nmatches++;
	}
	AhoCorasick(vector<string>& pat) : N(1, -1) {
		rep(i,0,sz(pat)) insert(pat[i], i);
		N[0].back = sz(N);
		N.emplace_back(0);

		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = N[n].back;
			rep(i,0,alpha) {
				int &ed = N[n].next[i], y = N[prev].next[i];
				if (ed == -1) ed = y;
				else {
					N[ed].back = y;
					(N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
						= N[y].end;
					N[ed].nmatches += N[y].nmatches;
					q.push(ed);
				}
			}
		}
	}
	vi find(string word) {
		int n = 0;
		vi res; // ll count = 0;
		for (char c : word) {
			n = N[n].next[c - first];
			res.push_back(N[n].end);
			// count += N[n].nmatches;
		}
		return res;
	}
};

struct Node {
	int lo, hi, mid;
	multiset<int> s;
	int val = 0;
	Node *left, *right;

	Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {
		if(l == r - 1) return;
		left = new Node(lo, mid);
		right = new Node(mid, hi);
	}

	void update(int l, int r, int ls, int x) {
		if(l >= hi || r <= lo) return;
		if(r >= hi && l <= lo) {
			if(ls) s.erase(s.lower_bound(ls));
			s.insert(x);
			val = *prev(s.end());
			return;
		}
		left->update(l, r, ls, x);
		right->update(l, r, ls, x);
	}

	int query(int i) {
		if(lo == hi - 1) return val;
		return max(val, (i < mid ? left : right)->query(i));
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q; cin >> n >> q;
	vector<string> a(n);
	for(string &x: a) cin >> x;
	AhoCorasick AC(a);

	vector<vector<int>> adj(n);
	for(int i = 0; i<n; i++) {
		if(AC.backp[i] == -1) continue;
		adj[AC.backp[i]].push_back(i);
	}

	vector<int> tour;
	vector<pair<int, int>> idxs(n);
	vector<int> vis(n);
	auto dfs = [&](int u, auto&& dfs) -> void {
		vis[u] = 1;
		idxs[u].first = sz(tour);
		tour.push_back(u);
		for(int v: adj[u]) dfs(v, dfs);
		idxs[u].second = sz(tour);
	};
	for(int i = 0; i<n; i++) if(!vis[i] && AC.backp[i] == -1) dfs(i, dfs);

	Node st(0, tour.size());
	vector<int> vals(n);
	while(q--) {
		int t; cin >> t;
		if(t == 1) {
			int i, x; cin >> i >> x;
			--i;
			st.update(idxs[i].first, idxs[i].second, vals[i], x);
			vals[i] = x;
		} else {
			int best = -1;
			string s; cin >> s;
			vector<int> pos = AC.find(s);
			for(int x: pos) if(x != -1) {
				best = max(best, st.query(idxs[x].first));
			}
			cout << best << '\n';
		}
	}
}

#include <bits/stdc++.h>
using namespace std;

#define int ll
using ll = long long;

struct Node {
	int lo, hi;
	ll val = 0, lazyMul = 0, lazySta = 0;
	Node *left, *right;

	Node(int l, int r): lo(l), hi(r) {
		if(l == r - 1) return;
		
		int mid = (lo + hi) / 2;
		left = new Node(lo, mid);
		right = new Node(mid, hi);
	}

	void apply(int r, int x) {
		int start = r - hi - 1;
		int end = hi - lo + start;
		int t = (end * (end + 1) / 2) - (start * (start + 1) / 2);
		val = t * x;
		lazyMul = x;
		lazySta = r;
	}

	void push() {
		if(lo == hi - 1 || !lazyMul) return;
		left->apply(lazySta, lazyMul);
		right->apply(lazySta, lazyMul);
		lazySta = lazyMul = 0;
	}

	void update(int l, int r, int x) {
		if(l >= hi || r <= lo) return;
		if(r >= hi && l <= lo) return void(apply(r, x));
		push();
		left->update(l, r, x);
		right->update(l, r, x);
		val = left->val + right->val;
	}

	ll query(int l, int r) {
		if(l >= hi || r <= lo) return 0;
		if(r >= hi && l <= lo) return val;
		push();
		return left->query(l, r) + right->query(l, r);
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, q; cin >> n >> m >> q;

	vector<pair<int, int>> hs(m);
	for(int i = 0; i<m; i++)
		cin >> hs[i].first;
	for(int i = 0; i<m; i++)
		cin >> hs[i].second;
	sort(hs.begin(), hs.end());

	set<pair<int, int>> harbors;
	for(int i = 0; i<m; i++) harbors.insert(hs[i]);

	Node st(0, n);
	for(int i = 0; i<m-1; i++) {
		st.update(hs[i].first, hs[i+1].first, hs[i].second);
	}

	for(int i = 0; i<q; i++) {
		int t; cin >> t;
		if(t == 1) {
			int x, v; cin >> x >> v;
			auto ne = harbors.lower_bound({x, 0});
			st.update(x, ne->first, v);

			ne--;
			st.update(ne->first, x, ne->second);

			harbors.insert({x, v});
		} else {
			int l, r; cin >> l >> r;
			l--;
			cout << st.query(l, r) << "\n";
		}
	}
}

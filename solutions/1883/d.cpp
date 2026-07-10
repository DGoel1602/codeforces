#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

struct Node {
	int lo, hi;
	int val = 0;
	Node *left = nullptr, *right = nullptr;

	Node(int l, int r): lo(l), hi(r) { }

	void check() {
		if(left != nullptr) return;
		int mid = (lo + hi)/2;
		left = new Node(lo, mid);
		right = new Node(mid, hi);
	}

	void update(int i, int x) {
		if(lo == hi - 1) return void(val += x);
		check();
		int mid = (lo + hi)/2;
		if(i < mid) left->update(i, x);
		else right->update(i, x);
		val = left->val + right->val;
	}

	int query(int l, int r) {
		if(l >= hi || r <= lo) return 0;
		if(r >= hi && l <= lo) return val;
		int res = 0;
		if(left != nullptr) res += left->query(l, r);
		if(right != nullptr) res += right->query(l, r);
		return res;
	}
};

void solve() {
	int q; cin >> q;
	Node sts(0, 1e9+5), ste(0, 1e9+5);
	ll inters = 0; 
	ll segs = 0;
	while(q--) {
		char t; int l, r; cin >> t >> l >> r;
		if(t == '+') {
			int ints = segs - (ste.query(0, l) + sts.query(r+1, 1e9+5));
			inters += ints;
			sts.update(l, 1);
			ste.update(r, 1);
			segs++;
		} else {
			int ints = segs - (ste.query(0, l) + sts.query(r+1, 1e9+5)) - 1;
			inters -= ints;
			sts.update(l, -1);
			ste.update(r, -1);
			segs--;
		}
		cout << (inters == (segs * (segs-1))/2 ? "NO\n" : "YES\n");
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	solve();
}

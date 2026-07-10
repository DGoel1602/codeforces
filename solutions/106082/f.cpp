#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
	int lo, hi;
	ll val = 0;
	Node *left, *right;

	Node(int l, int r): lo(l), hi(r) {
		if(l == r - 1) return;
		int mid = (lo + hi) / 2;
		left = new Node(lo, mid);
		right = new Node(mid, hi);
	}

	void update(int i, ll x) {
		if(lo == hi - 1) return void(val += x);
		int mid = (lo + hi) / 2;
		if(i < mid) left->update(i, x);
		else right->update(i, x);
		val = left->val + right->val;
	}

	ll query(int l, int r) {
		if(l >= hi || r <= lo) return 0;
		if(r >= hi && l <= lo) return val;
		return left->query(l, r) + right->query(l, r);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n; Node st(0, n);
	for(int i = 0; i<n; i++) {
		int x; cin >> x;
		st.update(i, x);
	}
	int q; cin >> q;
	for(int i = 0; i<q; i++) {
		char t; cin >> t;
		if(t == 'R') {
			int a, b; cin >> a >> b;
			a--;
			cout << st.query(a, b) << "\n";
		} else {
			int a, b; cin >> a >> b;
			a--;
			st.update(a, b);
		}
	}
}

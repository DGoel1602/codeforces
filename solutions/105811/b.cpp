#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using pii = pair<int, int>;

pii merge(pii a, pii b) { return {a.first + b.first, a.second + b.second}; };

struct Node {
	int lo, hi, mid;
	pii val = {0, 0};
	Node *left, *right;
	Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {
		if(l == r - 1) return;
		left = new Node(lo, mid);
		right = new Node(mid, hi);
	}
	void update(int i) {
		if(lo == hi - 1) return void(val = {lo, 1});
		if(i < mid) left->update(i);
		else right->update(i);
		val = merge(left->val, right->val);
	}
	pii query(int l, int r) {
		if(l >= hi || r <= lo) return {0, 0};
		if(r >= hi && l <= lo) return val;
		return merge(left->query(l, r), right->query(l, r));
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	Node st(0, n+1);
	ll res = 0;
	for(ll x: a) {
		pii ch = st.query(x+1, n+1);
		st.update(x);
		res += ch.first + x * ch.second;
	}
	cout << res << '\n';
}

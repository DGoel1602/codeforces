#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

struct Data {
	int mi_val = 1e9, mx_val = 0, hb = 0;
};

Data merge(Data left, Data right, int sz) {
	Data n;
	n.hb = max(left.hb, right.hb);
	if(left.mx_val > right.mi_val) n.hb = sz;
	n.mx_val = max(left.mx_val, right.mx_val);
	n.mi_val = min(left.mi_val, right.mi_val);
	return n;
}

struct Node {
	int lo, hi, mid;
	Node *left, *right;
	Data val;

	Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {
		if(l == r - 1) return;
		left = new Node(lo, mid);
		right = new Node(mid, hi);
	}

	void update(int i, int x) {
		if(lo == hi - 1) return void(val.mi_val = val.mx_val = x);
		if(i < mid) left->update(i, x);
		else right->update(i, x);
		val = merge(left->val, right->val, (hi - lo) / 2);
	}
};

void solve() {
	int n, q; cin >> n >> q;
	vi a(n);
	for(int &x: a) cin >> x;

	int tsz = n;
	while(__builtin_popcount(tsz) > 1) tsz++;
	Node st(0, tsz);
	for(int i = 0; i<n; i++) st.update(i, a[i]);
	cout << st.val.hb << '\n';
	while(q--) {
		int i, x; cin >> i >> x;
		st.update(i, x);
		cout << st.val.hb << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

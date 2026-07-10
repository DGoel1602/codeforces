#include <bits/stdc++.h>
#include <string>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

pii merge(pii a, pii b) {
	return {a.first + b.first, a.second + b.second};
}

struct Node {
	int lo, hi;
	pii val;
	int lazy = 0;
	Node *left, *right;

	Node(int l, int r): lo(l), hi(r) {
		if(l == r - 1) return;
		int mid = (lo + hi) / 2;
		left = new Node(lo, mid);
		right = new Node(mid, hi);
	}

	void apply() {
		val = {0, 0};
		lazy = 1;
	}

	void push() {
		if(lo == hi - 1 || !lazy) return;
		left->apply();
		right->apply();
		lazy = 0;
	}

	void update(int i) {
		if(lo == hi - 1) {
			val.first += lo; val.second++;
			return;
		}
		push();
		int mid = (lo + hi) / 2;
		if(i < mid) left->update(i);
		else right->update(i);
		val.first = left->val.first + right->val.first;
		val.second = left->val.second + right->val.second;
	}

	pii query(int l, int r) {
		if(l >= hi || r <= lo) return {0, 0};
		if(r >= hi && l <= lo) return val;
		push();
		return merge(left->query(l, r), right->query(l, r));
	}
};

Node st(0, 1e6 + 5);

void solve() {
	int n, m; cin >> n >> m;
	st.apply();

	vvi a(n, vi(m, 0));
	for(auto &vec: a) for(auto &x: vec) cin >> x;

	int res = 0;
	for(int j = 0; j<m; j++) {
		for(int i = 0; i<n; i++) {
			pii abo = st.query(a[i][j] + 1, 1e6 + 3);
			pii bel = st.query(0, a[i][j]);
			res += abo.first - a[i][j] * abo.second;
			res += a[i][j] * bel.second - bel.first;
			st.update(a[i][j]);
		}
		st.apply();
	}

	cout << res << "\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

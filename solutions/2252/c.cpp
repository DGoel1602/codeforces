#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

pii merge(pii a, pii b) {
	return {a.first + b.first, a.second + b.second};
}

struct Node {
	int lo, hi, mid;
	pii val = {0, 0};
	Node *left = nullptr, *right = nullptr;
	Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {}
	void chl() {
		if(lo == hi - 1 || left != nullptr) return;
		left = new Node(lo, mid);
	}
	void chr() {
		if(lo == hi - 1 || right != nullptr) return;
		right = new Node(mid, hi);
	}
	void update(int i) {
		if(lo == hi - 1) { 
			val.first++;
			val.second += lo;
			return;
		}
		if(i < mid) chl(), left->update(i);
		else chr(), right->update(i);

		val = {0, 0};
		if(left != nullptr) val = merge(val, left->val);
		if(right != nullptr) val = merge(val, right->val);
	}
	int cnt(int s) {
		if(lo == hi - 1)
			return (s + lo - 1) / lo;
		if(right != nullptr && right->val.second >= s) return right->cnt(s);
		chl();
		pii rv = right == nullptr ? make_pair(0LL, 0LL) : right->val;
		return rv.first + left->cnt(s - rv.second);
	}
};


void solve() {
	int n, m; cin >> n >> m;
	vi a(n);
	for(int &x: a) cin >> x;
	vvi g(n, vi(m, 0));
	for(auto &vec: g) for(int &x: vec) cin >> x;
	Node st(0, 1e9 + 5);
	int best = m;
	for(int i = n-1; i>=0; i--) {
		for(int j = 0; j<m; j++) st.update(g[i][j]);
		if(st.val.second >= a[i]) best = min(best, st.cnt(a[i]));
	}
	cout << best << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

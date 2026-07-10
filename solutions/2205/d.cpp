#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

struct Node {
	int lo, hi;
	Node *left, *right;
	int val = 0;

	Node(int l, int r): lo(l), hi(r) {
		if(l == r - 1) return;
		int mid = (lo + hi)/2;
		left = new Node(lo, mid);
		right = new Node(mid, hi);
	}

	void update(int i, int x) {
		if(lo == hi - 1) return void(val = x);
		int mid = (lo + hi) / 2;
		if(i < mid) left->update(i, x);
		else right->update(i, x);
		val = left->val + right->val;
	}

	int query(int l, int r) {
		if(l >= hi || r <= lo) return 0;
		if(r >= hi && l <= lo) return val;
		return left->query(l, r) + right->query(l, r);
	}
};

void solve() {
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;

	stack<int> ms;
	vi lb(n, -1);
	rep(i, 0, n) {
		while(ms.size() && a[ms.top()] < a[i]) ms.pop();
		if(ms.size()) lb[i] = ms.top();
		ms.push(i);
	}

	stack<int> ms2;
	vi rb(n, n);
	for(int i = n-1; i>=0; i--) {
		while(ms2.size() && a[ms2.top()] < a[i]) ms2.pop();
		if(ms2.size()) rb[i] = ms2.top();
		ms2.push(i);
	}

	Node st(0, n + 5);
	int cost = 0;
	map<int, int> idcs;
	rep(i, 0, n) idcs[a[i]] = i;

	for(auto [el, idx]: idcs) {
		int mc = min(idx - lb[idx] - 1 - st.query(lb[idx]+1, idx), rb[idx] - idx - 1 - st.query(idx+1, rb[idx]));
		cost += mc;
		st.update(idx, mc);
	}
	cout << cost << "\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

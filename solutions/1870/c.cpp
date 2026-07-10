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
	int type;
	Node *left, *right;

	Node(int l, int r, int t): lo(l), hi(r), type(t) {
		val = (type ? 0 : 1e9);
		if(l == r - 1) return;
		int mid = (l + r)/2;
		left = new Node(lo, mid, t);
		right = new Node(mid, hi, t);
	}

	void update(int i, int x) {
		if(lo == hi - 1) return void(val = (type ? max(val, x) : min(val, x)));
		int mid = (lo + hi) / 2;
		if(i < mid) left->update(i, x);
		else right->update(i, x);
		val = type ? (max(left->val, right->val)) : min(left->val, right->val);
	}

	int query(int l, int r) {
		if(l >= hi || r <= lo) return (type ? 0 : 1e9);
		if(r >= hi && l <= lo) return val;
		return type ? max(left->query(l, r), right->query(l, r))
								: min(left->query(l, r), right->query(l, r));
	}
};

void solve() {
	int n, k; cin >> n >> k;
	vi a(n); 
	for(int &x: a) cin >> x;
	
	vector<int> left(k+1, 1e9), right(k+1, -1);
	Node st1(0, k + 5, 0), st2(0, k + 5, 1);
	rep(i, 0, n) {
		st1.update(a[i], i);
		left[a[i]] = min(left[a[i]], st1.query(a[i], k+4));
	}
	for(int i = n-1; i>=0; i--) {
		st2.update(a[i], i);
		right[a[i]] = max(right[a[i]], st2.query(a[i], k+4));
	}
	vi res(k+1);
	for(int i = 1; i<=k; i++) {
		res[i] = (right[i] - left[i] + 1) * 2;
	}

	for(int i = 1; i<=k; i++) cout << (res[i] < 0 ? 0 : res[i]) << " ";
	cout << "\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

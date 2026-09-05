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
	int lo, hi, mid;
	int val = 0, tot = 0;
	Node *left = nullptr, *right = nullptr;
	
	Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {
		if(l == r - 1) return;
		left = new Node(lo, mid);
		right = new Node(mid, hi);
	}

	void update(int i, int x) {
		if(lo == hi - 1) {
			val = x;
			tot = lo * x;
			return;
		}
		if(i < mid) left->update(i, x);
		else right->update(i, x);
		val = left->val + right->val;
		tot = left->tot + right->tot;
	}

	int query(int tot) {
		if(lo == hi - 1) return lo;
		if(left->val >= tot) return left->query(tot);
		else return right->query(tot - left->val);
	}

	int query(int l, int r, int t) {
		if(l >= hi || r <= lo) return 0;
		if(r >= hi && l <= lo) return t ? tot : val;
		return left->query(l ,r, t) + right->query(l, r, t);
	}
};

// 1 4 7 9 10
// 1   4 7 10

void solve() {
	int n, k; cin >> n >> k;	
	vi a(n);
	for(int &x: a) cin >> x;

	vi res(n, 0);
	Node st(0, n + 1);
	for(int i = n-2; i>=1; i--) {
		int req_gap = max(0LL, (a[i+1] - a[i-1]) - k);
		if(req_gap) {
			int idx = st.query(req_gap);
			int sum = st.query(0, idx, 0);
			int tot = st.query(0, idx, 1);
			res[i] = (idx - i - 1) * req_gap - idx * sum  + tot;
		}
		st.update(i+1, k - (a[i+1] - a[i]));
	}
	for(int x: res) cout << x << " ";
	cout << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

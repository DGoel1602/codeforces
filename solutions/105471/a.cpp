#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

typedef uint64_t ull;
ll n, q, k, b; 
const ull off = 1e4;

struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator!=(H o) const { return get() != o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3;
vector<H> pows;

struct Data {
	H h = 0, rh = 0;
	int sz = 0;
};

Data merge(Data a, Data b) {
	return Data{a.h * pows[b.sz] + b.h, b.rh * pows[a.sz] + a.rh, a.sz + b.sz};
}

struct Node {
	int lo, hi, mid;
	Data val;
	Node *left, *right;

	Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {
		if(l == r - 1) return;
		left = new Node(lo, mid);
		right = new Node(mid, hi);
	}
	
	void update(int i, int x) {
		if(lo == hi - 1) {
			val.rh = (k - x) + off;
			val.h = x + off;
			val.sz = 1;
			return;
		}
		if(i < mid) left->update(i, x);
		else right->update(i, x);
		val = merge(left->val, right->val);
	}

	Data query(int l, int r) {
		//cout << l << " " << r << " " << lo << " " << hi << endl;
		if(l >= hi || r <= lo) return Data();
		if(r >= hi && l <= lo) return val;
		return merge(left->query(l, r), right->query(l, r));
	}
};

struct Node3 {
	int lo, hi, mid;
	int val = 0;
	int lazy = 0;
	Node3 *left, *right;

	Node3(int l, int r): lo(l), hi(r), mid((l+r)/2) {
		if(l == r - 1) return;
		left = new Node3(lo, mid);
		right = new Node3(mid, hi);
	}

	void apply(int x) {
		lazy += x;
		val += x;
	}

	void push() {
		if(lo == hi - 1) return;
		left->apply(lazy);
		right->apply(lazy);
		lazy = 0;
	}

	void update(int l, int r, int x) {
		if(l >= hi || r <= lo) return;
		if(r >= hi && l <= lo) return apply(x);
		push();
		left->update(l, r, x);
		right->update(l, r, x);
		val = (left->val + right->val);
	}

	int query(int i) {
		if(lo == hi - 1) return val;
		push();
		return (i < mid ? left : right)->query(i);
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	pows.push_back(1);
	for(int i = 0; i<1e5; i++) pows.push_back(pows.back() * C);

	cin >> n >> q >> k >> b;
	vector<int> a(n);
	for(int &x: a) cin >> x;

	Node st_diff(0, n-1);
	Node3 st_val(0, n);
	for(int i = 0; i<n; i++) st_val.update(i, i+1, a[i]);
	for(int i = 0; i<(n-1); i++) 
		st_diff.update(i, a[i+1]-a[i]);

	while(q--) {
		int t; cin >> t;
		if(t == 1) {
			int l, r, v; cin >> l >> r >> v;
			--l; --r;
			st_val.update(l, r+1, v);
			if(l != 0) st_diff.update(l-1, st_val.query(l)-st_val.query(l-1));
			if(r != n-1) st_diff.update(r, st_val.query(r+1)-st_val.query(r));
		} else {
			int i; cin >> i;
			--i;
			if(i == 0 || i == n - 1) {
				cout << "0\n";
				continue;
			}
			if(st_val.query(i+1)-st_val.query(i-1) != k + b) {
				cout << "0\n";
				continue;
			}
			int lo = 0, hi = min(i-1, n-1-(i+1));
			while(lo != hi) {
				int m = lo + (hi - lo + 1) / 2;
				H need = st_diff.query(i+1, i+m+1).rh;
				H have = st_diff.query(i-m-1, i-1).h;
				//cout << m << " " << need.get() << " " << have.get() << endl;
				if(need != have) hi = m - 1;
				else lo = m;
			}
			cout << lo + 1 << '\n';
		}
	}
}

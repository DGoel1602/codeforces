#include <bits/stdc++.h>
#include <filesystem>
#include <ios>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

struct Data {
	int pref = 0, sum = 0;
};

Data merge(Data a, Data b) {
	Data n;
	n.sum = a.sum + b.sum;
	n.pref = max(a.pref, a.sum + b.pref);
	return n;
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
	void apply(int x) {
		val.pref += x, val.sum += x;
	}
	void update(int i, int x) {
		if(lo == hi - 1) return void(apply(x));
		if(i < mid) left->update(i, x);
		else right->update(i, x);
		val = merge(left->val, right->val);
	}
	Data query(int l, int r) {
		if(hi <= l || lo >= r) return Data();
		if(lo >= l && hi <= r) return val;
		return merge(left->query(l, r), right->query(l, r));
	}
};

void solve() {
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;
	Node st(0, n+1);
	vi contrib(n+1);
	vi up(n+3), lo(n+3);
	set<int> cur;
	vi pos(n+1);
	for(int i = 0; i<n; i++) {
		int x = a[i];
		int adding = 1;
		pos[x] = i;
		if(cur.count(x-1)) adding--, lo[x] = 1;
		if(cur.count(x+1)) adding--, up[x] = 1;
		contrib[x] = adding;
		st.update(i, adding);
		cur.insert(x);
	}
	int res = st.val.pref <= 2;
	for(int i = 1; i<n; i++) {
		int x = a[i-1];
		st.update(pos[x], -contrib[x]);
		contrib[x] = (x == 1 || x == n ? 0 : -1);
		st.update(pos[x], contrib[x]);
		up[x] = lo[x] = 1;

		if(up[x-1]) {
			st.update(pos[x-1], +1);
			up[x-1] = 0;
			contrib[x-1]++;
		}
		if(lo[x+1]) {
			st.update(pos[x+1], +1);
			lo[x+1] = 0;
			contrib[x+1]++;
		}

		Data ret = merge(st.query(i, n+1), st.query(0, i));
		res += ret.pref <= 2;
	}
	cout << res << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

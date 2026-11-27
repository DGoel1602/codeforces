#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;

#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define sz(x) (int)(x).size()

struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos) {
		for (s[pos += n]++; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k; cin >> n >> k;
	vi a(n);
	for(int &x: a) cin >> x;

	vector<pair<int, int>> els;
	for(int i =0; i<n; i++) els.push_back({a[i], i});
	sort(all(els));

	auto works = [&](int idx) -> bool {
		vector<int> vals(n);
		Tree st(2e5 + 10);
		for(int i = 0; i<n; i++) {
			if(make_pair(a[i], i) <= make_pair(a[idx], idx)) vals[i] = 1;
			else vals[i] = -1;
		}

		int res = 0;
		int cur = 0;
		st.update(1e5+5+cur);

		for(int i = 0; i<n; i++) {
			cur += vals[i];

			res += st.query(0, 1e5+5+cur);
			st.update(1e5+5+cur);
		}

		return res >= k;
	};

	int lo = 0, hi = n-1;
	while(lo != hi) {
		int m = lo + (hi - lo) / 2;
		if(!works(els[m].second)) lo = m + 1;
		else hi = m;
	}
	cout << els[lo].first << '\n';
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, int>;

struct Tree {
	typedef pii T;
	static constexpr T unit = {0LL, 0};
	T f(T a, T b) { return {a.first + b.first, a.second + b.second}; }
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
        pos += n;
		for (s[pos] = f(s[pos], val); pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) {
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
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    vector<int> cp(a);
    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(), cp.end()), cp.end()); 
    for(int &x: a) x = lower_bound(cp.begin(), cp.end(), x) - cp.begin();

    vector<int> freq(n+1, 0), nf(n+1, 0);
    for(int x: a) freq[x]++;

    ll res = 0;
    Tree st(n+5);
    for(int c: freq) if(c) st.update(c, {c, 1});

    for(int i = 0; i<n; i++) {
        st.update(freq[a[i]], {-freq[a[i]], -1});
        freq[a[i]]--;
        st.update(freq[a[i]], {freq[a[i]], 1});
        nf[a[i]]++;
        res += st.query(0, nf[a[i]]).first;
        res += (ll)st.query(nf[a[i]], n+4).second * (nf[a[i]]-1);
    }
    cout << res << endl;
}

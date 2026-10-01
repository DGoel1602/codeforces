#include <bits/stdc++.h>
#include <cassert>
using namespace std;

mt19937 rng(time(NULL));

const int M = 64;
using B = bitset<M>;

#define int long long
template<class T> struct Basis {
	B basis[M], which[M], has_val;
	T val[M];
	Basis() { memset(val, 0, sizeof(val)); }
	bool add(B v, T x) {
		if (v.none()) return false;
		B cur; int ind = -1;
		for (int i = M - 1; i >= 0; i--) if (v[i]) {
			if (has_val[i])
				v ^= basis[i], cur ^= which[i];
			else if (ind < 0) ind = i;
		}
		if (ind < 0) return false;
		basis[ind] = v, val[ind] = x, has_val[ind] = 1;
		which[ind] = cur, which[ind][ind] = 1;
		return true;
	}
	vector<T> get(B v) const {
		if (v.none()) return {{}};
		B w;
		for (int i = 0; i < M; i++)
			if (v[i]) v ^= basis[i], w ^= which[i];
		if (v.any()) return {};

		vector<T> res;
		for (int i = 0; i < M; i++)
			if (w[i]) res.push_back(val[i]);
		return res;
	}
};

signed main() {
    int n; cin >> n;

    set<int> s = {n};
    vector<int> nums = {n};
    Basis<int> bs;
    bs.add(B(n), n);
    vector<string> res;
    auto add = [&](int a, int b) -> int {
        assert(s.count(a));
        assert(s.count(b));
        s.insert(a + b);
        nums.push_back(a + b);
        res.push_back(to_string(a) + " + " + to_string(b));
        bs.add(B(a + b), a + b);
        return a + b;
    };
    auto xo = [&](int a, int b) -> int {
        assert(s.count(a));
        assert(s.count(b));
        s.insert(a ^ b);
        nums.push_back(a ^ b);
        res.push_back(to_string(a) + " ^ " + to_string(b));
        bs.add(B(a + b), a + b);
        return a ^ b;
    };

    int cur = n;
    while(cur <= 1e18) {
        cur = add(cur, cur);
    }

    auto fn = bs.get(B(1));
    while((fn = bs.get(B(1))).empty()) {
        int a = rng()%nums.size(), b = rng() % nums.size();
        add(nums[a], nums[b]);
    }
    xo(n, n);
    int ls = 0;
    for(int x: fn) {
        ls = xo(ls, x);
    }

    assert(s.count(1));
    cout << res.size() << '\n';
    for(string x: res) cout << x << '\n';
}

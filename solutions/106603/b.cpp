#include <algorithm>
#include <assert.h>
#include <bits/stdc++.h>
#include <random>
using namespace std;

#define sz(x) (int)(x).size()

#define int long long
using ll = long long;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	ll query(int l, int r) { // sum of values in [0, pos)
		return query(r) - query(l);
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
	int lower_bound_opp(ll sum) {
    if (sum <= 0) return sz(s);
    sum = query(sz(s)) - sum;
    if (sum < 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
        if (pos + pw <= sz(s) && s[pos + pw-1] <= sum)
            pos += pw, sum -= s[pos-1];
    }
    return pos;
	}
};

bool comp(int x, int y) {
	return x > y;
}
int sort(vector<int> &arr) {
	int n = arr.size();
	for(int iter = 0; iter < (n-1); iter = iter + 1) {
		bool done_sorting = true;
		for(int i = 0; i < (n-1); i = i + 1) {
			if(comp(arr[i], arr[i+1])) {
				done_sorting = false;
				swap(arr[i], arr[i+1]);
			}
		}

		for(int i = n-1; i > 0; i = i - 1) {
			if(comp(arr[i-1], arr[i])) {
				done_sorting = false;
				swap(arr[i-1], arr[i]);
			}
		}

		if(done_sorting) return iter + 1;
	}
	return 0;
}

mt19937 rng(time(NULL));

vector<int> inp() {
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	return a;
}

vector<int> inp_fake() {
	int n = 5;
	vector<int> a(n);
	for(int &x: a) x = rng()%n;
	return a;
}

void solve(vector<int> a) {
	cin.tie(0)->sync_with_stdio(0);
	int n = a.size();

	vector<int> cp(a);
	sort(cp.begin(), cp.end());
	cp.erase(unique(cp.begin(), cp.end()), cp.end());
	for(int &x: a) x = lower_bound(cp.begin(), cp.end(), x)- cp.begin();

	vector<vector<int>> idxs(n);
	for(int i = 0; i<n; i++) idxs[a[i]].push_back(i);

	vector<int> aft(n), bef(n);
	int invs = 0;
	FT st1(n);
	for(int i = n-1; i>=0; i--) {
		aft[i] = st1.query(a[i]);
		st1.update(a[i], 1);
	}
	st1 = FT(n);
	for(int i = 0; i<n; i++) {
		bef[i] = st1.query(a[i]+1, n);
		invs += bef[i];
		st1.update(a[i], 1);
	}

	vector<int> res(n);
	FT lit(n);
	for(int num = n-1; num>=0; num--) {
		for(int i: idxs[num]) {
			if(aft[i] == bef[i]) {
				res[i] = aft[i];
				continue;
			}
			if(bef[i] < aft[i]) continue;
			res[i] = lit.query(i + aft[i] - bef[i] + 1);
		}
		for(int i: idxs[num]) lit.update(i, 1);
	}

	lit = FT(n);
	for(int num = 0; num<n; num++) {
		for(int i: idxs[num]) {
			if(aft[i] == bef[i]) {
				res[i] = aft[i];
				continue;
			}
			if(bef[i] > aft[i]) continue;
			res[i] = lit.query(i + aft[i] - bef[i], n);}
		for(int i: idxs[num]) lit.update(i, 1);
	}

	//for(int x: res) cout << x << " ";
	//cout << endl;

	cout << (*max_element(res.begin(), res.end()) + 1) * 2 * (n-1) + invs << '\n';
}

signed main() {
	for(int i = 0; i<1; i++) {
		solve(inp());
	}
}

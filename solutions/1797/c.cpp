#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

int n, m;

bool isValid(pii p) {
	return !(p.first <= 0 || p.first > n || p.second <= 0 || p.second > m);
}

int query(pii p) {
	cout << "? " << p.first << " " << p.second << endl;
	int r; cin >> r;
	return r;
}

int sign(int x) {
	return x < 0 ? -1 : 1;
}

void solve() {
	cin >> n >> m;
	int r = query({1, 1}), r2 = query({n, m});
	pair<pii, pii> ops = {{1 + r, m - r2}, {n - r2, 1 + r}};

	if(ops.first.first == ops.second.first) {
		ops.first.second = clamp(ops.first.second, 1, m);
		ops.second.second = clamp(ops.second.second, 1, m);
	} else if(ops.first.second == ops.second.second) {
		ops.first.first = clamp(ops.first.first, 1, n);
		ops.second.first = clamp(ops.second.first, 1, n);
	}
	if(!isValid(ops.first)) swap(ops.first, ops.second);

	int r3 = query(ops.first);
	pii res = ops.first;
	if(ops.first.first == ops.second.first) {
		res.second += r3 * sign(ops.second.second - ops.first.second);
	} else if(ops.first.second == ops.second.second) {
		res.first += r3 * sign(ops.second.first - ops.first.first);
	} else if(r3) res = ops.second;
	cout << "! " << res.first << " " << res.second << endl;
}

int main() {
	int t; cin >> t;
	while(t--) solve();
}


// 000100
// 000100
// 000100
// 111111
// 010000
// 010000
// 010000
// 010000

#include <bits/stdc++.h>
#include <numeric>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
	int n, k; cin >> n >> k;
	vi a(n); 
	for(int &x: a) cin >> x;
	rep(i, 0, n) a[i] = a[i] < 0 ? 1 : 0;
	k -= accumulate(all(a), 0);

	if(accumulate(all(a), 0) == 0) return void(cout << "0\n");
	if(k < 0) return void(cout << "-1\n");

	vi gaps;
	int ls = -1;
	rep(i, 0, n) {
		if(a[i] == 0) continue;
		if(ls != -1) gaps.push_back(i - ls - 1);
		ls = i;
	}
	sort(all(gaps));

	int base = 1 + gaps.size() * 2 + 1;
	int op1 = base;
	for(int i = 0, _k = k; _k >= 0 && i < gaps.size(); i++) {
		_k -= gaps[i];
		if(_k >= 0) op1 -= 2;
	}
	int op2 = 1e9;
	if(k >= n - ls - 1) {
		op2 = base - 1;
		for(int i = 0, _k = k - (n - ls - 1); _k >= 0 && i < gaps.size(); i++) {
			_k -= gaps[i];
			if(_k >= 0) op2 -= 2;
		}
	}
	cout << min(op1, op2) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while(t--) solve();
}

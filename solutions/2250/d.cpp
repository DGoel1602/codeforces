#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

const ll mod = 998244353;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
	int n; cin >> n;
	vi a(n-1);
	for(int &x: a) cin >> x;

	vi cp(a);
	sort(all(cp));
	if(cp.back() == n) return void(cout << "0\n");
	vi cp3(a);
	cp3.erase(unique(all(cp3)), cp3.end());
	sort(all(cp3));
	vi cp2(cp3);
	cp2.erase(unique(all(cp2)), cp2.end());
	if(cp3.size() != cp2.size()) return void(cout << "0\n");

	vi cp4(a);
	sort(all(cp4));
	int c = 0;
	for(int x: cp4) {
		c++;
		if(x < c) return void(cout << "0\n");
	}
	
	int res = 1;
	int l = 0, r = n - 2;
	int cur = 0, mx = 0;
	while(l < r) {
		int mn = min(a[l], a[r]);
		if (mn < mx) return void(cout << "0\n");
		if(a[l] < a[r]) {
			if(a[l] != mx) {
				cur += a[l] - mx - 1;
				mx = a[l];
				l++;
				continue;
			}
			res = (res * cur) % mod;
			cur--;
			l++;
		} else {
			if(a[r] != mx) {
				cur += a[r] - mx - 1;
				mx = a[r];
				r--;
				continue;
			}
			res = (res * cur) % mod;
			cur--;
			r--;
		}
	}
	cout << (res * 2) % mod << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

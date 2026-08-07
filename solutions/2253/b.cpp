#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;
	vi b;
	vi o;
	rep(i, 0, n) {
		if(i == 0 || a[i] != a[i-1]) {
			b.push_back(a[i]);
			o.push_back(i < n - 1 && a[i] == a[i+1]);
		}
	}
	n = b.size();
	int mx = 0;
	rep(i, 0, b.size()) {
		if(i < n - 2 && b[i+2] != b[i] && o[i]) mx = max(mx, 1);
		if(i >= 2 && b[i-2] != b[i] && o[i]) mx = max(mx, 1);
		if(i == 1 && o[i]) mx = max(mx, 1);
		if(i == n - 2 && o[i]) mx = max(mx, 1);
		if(i >= 1 && o[i] && o[i-1]) mx = max(mx, 2);
		if(i < n - 1 && o[i] && o[i+1]) mx = max(mx, 2);
	}
	cout << b.size() + mx << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

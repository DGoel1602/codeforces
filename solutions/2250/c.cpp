#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
	int n; cin >> n;
	vector<array<int, 4>> a(n);
	for(auto &[l, r, u, v]: a) cin >> l >> r >> u >> v;
	for(int m = n; m>=0; m--) {
		int cur = 1;
		for(auto [l, r, u, v]: a) {
			int ri = m - cur + 1;
			if((l > cur || r < cur) && (u > ri || v < ri)) cur++;
			if(cur == m+1) return void(cout << m << '\n');
		}
	}
	cout << "0\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

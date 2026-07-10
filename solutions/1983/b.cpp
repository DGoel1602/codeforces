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
	int n, m; cin >> n >> m;
	vector<string> grid(n), g2(n);
	for(string &x: grid) cin >> x;
	for(string &x: g2) cin >> x;
	for(int i = 0; i<n; i++) {
		int a1 = 0, a2 = 0;
		for(int j = 0; j<m; j++) a1 += grid[i][j] - '0', a2 += g2[i][j] - '0';
		if(a1 % 3 != a2 % 3) return void(cout << "NO\n");
	}
	for(int i = 0; i<m; i++) {
		int a1 = 0, a2 = 0;
		for(int j = 0; j<n; j++) a1 += grid[j][i] - '0', a2 += g2[j][i] - '0';
		if(a1 % 3 != a2 % 3) return void(cout << "NO\n");
	}
	cout << "YES\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

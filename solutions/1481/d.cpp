#include <algorithm>
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
	vector<string> g(n);
	for(string &x: g) cin >> x;

	if(m & 1) {
			cout << "YES\n";
			for(int i = 0; i<m+1; i++) cout << (i % 2 ? 1 : 2) << " ";
			cout << '\n';
			return;
	}
	for(int i = 0; i<n; i++) for(int j = i+1; j<n; j++) {
		if(g[i][j] == g[j][i]) {
			cout << "YES\n";
			for(int k = 0; k<m+1; k++) cout << (k % 2 ? i + 1 : j + 1) << " ";
			cout << '\n';
			return;
		}
	}

	if(n < 3) return void(cout << "NO\n");
	vector<int> vec = {0, 1, 2};
	do {
		if(g[vec[0]][vec[1]] != g[vec[0]][vec[2]]) {
			cout << "YES\n";
			if(m % 4) cout << vec[2] + 1 << " ";
			cout << vec[0] + 1;
			for(int i = 0; i<m/4; i++) cout << " " << vec[1] + 1 << " " << vec[0] + 1 << " " << vec[2] + 1 << " " << vec[0] + 1;
			if(m % 4) cout << " " << vec[1] + 1;
			cout << '\n';
			return;
		}
	} while(next_permutation(all(vec)));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

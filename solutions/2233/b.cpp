#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
	int n; cin >> n;
	vi res2 = {1, 2, 2, 1, 1, 2, 1, 2};
	int curidx = 1;
	for(int i = 3; i<=n; i++) {
		vi res3;
		res3.push_back(i);
		for(int j = 0; j<curidx; j++) res3.push_back(res2[j]);
		res3.push_back(i);
		for(int j = curidx; j<res2.size(); j++) res3.push_back(res2[j]);
		swap(res3, res2);
		curidx++;
	}
	for(int x: res2) cout << x << " ";
	for(int i = n; i>=3; i--) cout << i << " ";
	for(int i = n; i>=3; i--) cout << i << " ";
	cout << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

// 1 2 2 1 1 2 1 2
// 3 1 3 2 2 1 1 2 1 2 3 3
// 4 3 1 4 3 2 2 1 1 2 1 2 4 3 4 3

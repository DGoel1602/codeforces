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
	string a, b; cin >> a >> b;
	vvi idxs(2), idxs_b(2);
	rep(i, 0, n) {
		if(a[i] == '1') idxs[i%2].push_back(i);
		if(b[i] == '1') idxs_b[i%2].push_back(i);
	}
	int res = 0;
	if(idxs[0].size() != idxs_b[0].size()) return void(cout << "-1\n");
	if(idxs[1].size() != idxs_b[1].size()) return void(cout << "-1\n");
	for(int i = 0; i<idxs[0].size(); i++) res += abs(idxs[0][i] - idxs_b[0][i]);
	for(int i = 0; i<idxs[1].size(); i++) res += abs(idxs[1][i] - idxs_b[1][i]);
	cout << res / 2 << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

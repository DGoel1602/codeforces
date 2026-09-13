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
	string s; cin >> s;

	const int MX = 4;
	vvi dp(n, vi(MX * 2 + 1, -1));
	auto go = [&](int i, int ls, auto&& go) {
		if(i == n) return 0;
		auto &ref = dp[i][ls];
		if(ref != -1) return ref;

		vi allowed = vi(MX);
		if(s[i] == '0') allowed = {0};
		else {
			for(int j = 0; j<MX; j++)
				allowed[j] = (s[i] == '+' ? 1 : -1) * (j + 1);
		}

		ref = 1e9;
		for(int x: allowed) {
			int going = x + MX;
			if(ls == going) continue;
			ref = min(ref, max(go(i+1, going, go), abs(ls - going)));
		}
		return ref;
	};
	int res = go(0, MX, go);
	cout << (res > 1e8 ? -1 : res) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

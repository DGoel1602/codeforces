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
	int n, s, x; cin >> n >> s >> x;
	string u; cin >> u;
	int tables = s, extseats = 0;
	int res = 0;

	vi pref(n, 0);
	rep(i, 0, n) pref[i] = (i == 0 ? 0 : pref[i-1]) + (u[i] != 'I');
	set<int> sits;
	rep(i, 0, n) if(u[i] == 'I') sits.insert(i);

	rep(i, 0, n) {
		char c = u[i];
		if(c == 'I') {
			if(tables) tables--, extseats += x - 1, res++;
		} else if(c == 'E') {
			if(extseats) extseats--, res++;
		} else {
			int cur = 0;
			for(int j = n-1; j>i; j--) {
				cur++;
				if(u[j] == 'I') cur = max(cur - x, 0);
			}
			if(extseats <= cur && tables) tables--, extseats += x - 1, res++;
			else if(extseats) extseats--, res++;
		}
	}
	cout << res << "\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

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
	int n, s, x; cin >> n >> s >> x;
	string u; cin >> u;
	int tables = s, extseats = 0;
	int res = 0;

	vector<int> curs(n, 0);
	int cur = 0;
	for(int j = n-1; j>0; j--) {
		cur++;
		if(u[j] == 'I') cur = max(cur - x, 0LL);
		curs[j-1] = cur;
	}

	rep(i, 0, n) {
		char c = u[i];
		if(c == 'I') {
			if(tables) tables--, extseats += x - 1, res++;
		} else if(c == 'E') {
			if(extseats) extseats--, res++;
		} else {
			if(extseats <= curs[i] && tables) tables--, extseats += x - 1, res++;
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

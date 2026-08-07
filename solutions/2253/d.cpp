#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int x, y; cin >> x >> y;
	int n = 1;
	while(n * (n + 1) / 2 <= x + y) n++;
	--n;
	int err = x + y - (n * (n + 1) / 2);
	int p_err = err / 2;
	int ideal = x - p_err;
	string res;
	rep(i, 0, n) res += 'Y';
	for(int i = n; i>=1; i--) {
		if(ideal >= i) ideal -= i, res[n - i] = 'X';
	}
	cout << res << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

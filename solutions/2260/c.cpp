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
	int x, y; cin >> x >> y;
	int res = 0;
	for(int i = 31; i>=0; i--) {
		int bit = (1 << i);
		if(((x + y) & bit) && res + bit <= x) res += (1 << i);
	}
	cout << x + y << " " << x - res << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

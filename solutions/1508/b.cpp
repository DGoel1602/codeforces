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
	int n, k; cin >> n >> k;
	int mx = 1LL << min(62LL, (n-1));
	if(k > mx) return void(cout << "-1\n");
	--k;
	vi ins(n+1, 1);
	for(int i = n-1; i>=0 && i>=(n-63); i--) {
		int bit = n - i - 1;
		if(bit >= 63) break;
		ins[i] = !((k >> bit) & 1LL);
	}
	int ls = 0;
	for(int i = 1; i<=n; i++) {
		if(!ins[i]) continue;
		for(int j = i; j>ls; j--) cout << j << " ";
		ls = i;
	}
	cout << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

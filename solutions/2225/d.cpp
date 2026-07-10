#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

const ll mod = 998244353;

void solve() {
	int n, x; cin >> n >> x;
	int res = 0;

	int bel = ((x + 3) / 4) % mod;
	int atb = x % 4 == 3;
	int ato = (x-1) % 4 == 3;
	int abo = (((n + 5) / 4) - bel - atb - ato) % mod;

	res = (res + (bel * abo) % mod) % mod;
	res = (res + (ato * abo) % mod) % mod;
	res = (res + (atb * bel) % mod) % mod;


	bel = ((x + 1) / 4) % mod;
	atb = x % 4 == 1;
	ato = (x-1) % 4 == 1;
	abo = (((n + 3) / 4) - bel - atb - ato) % mod;

	res = (res + (bel * abo) % mod) % mod;
	res = (res + (ato * abo) % mod) % mod;
	res = (res + (atb * bel) % mod) % mod;

	cout << res << "\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

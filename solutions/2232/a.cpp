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
	vi a(n);
	for(int &x: a) cin >> x;
	sort(all(a));
	int med = a[n/2];
	int bel = 0, abo = 0;
	for(int x: a) {
		if(x < med) bel++;
		if(x > med) abo++;
	}
	int res = min(bel, abo);
	bel -= res; abo -= res;

	cout << res + bel + abo << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

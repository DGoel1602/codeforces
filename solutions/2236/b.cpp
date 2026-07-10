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
	string s; cin >> s;
	vi f(k);
	rep(i, 0, n) if(s[i] == '1') f[i % k]++;
	rep(i, 0, k) if(f[i] & 1) return void(cout << "NO\n");
	cout << "YES\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

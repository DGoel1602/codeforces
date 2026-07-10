#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	vi pref(n+1);
	rep(i, 1, n+1) pref[i] = pref[i-1] + (s[i-1] == 'a' ? 1 : -1);
	int lf = pref[n];
	map<int, int> mp;
	mp[0] = 0;
	int best = 1e9;
	rep(i, 1, n+1) {
		mp[pref[i]] = i;
		if(mp.count(pref[i]-lf)) best = min(best, i - mp[pref[i]-lf]);
	}
	cout << (best < n ? best : -1) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

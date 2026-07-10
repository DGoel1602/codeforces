#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

const ll mod = 1e9 + 7;

void solve() {
	int n, c; cin >> n >> c;
	string s; cin >> s;

	if(s[n-1] == '0' || s[0] == '0') return void(cout << "-1\n");
	s[0] = s[n-1] = '1';
	if(s[1] == '?') s[1] = '0';

	int oc = c;
	for(int i = 0; i<n-1; i++) {
		if(s[i] == '1' && c % 2 == 0) c /= 2;
		else if(s[i] == '0') c /= gcd(i, c);
	}
	if(c == 1) return void(cout << "-1\n");

	int ex = 1e9;
	if(__builtin_popcountll(c) == 1) ex = 63 - __builtin_clzll(c) - 1;
	vector<pair<int, int>> sor;
	for(int i = n-1; i>=2; i--) if(s[i] == '?' && __gcd(i, c) > 1)
		sor.push_back({__gcd(i, c), i});

	sort(all(sor), greater<>());
	for(auto [_, idx]: sor) {
		if(ex) s[idx] = '1', ex--;
		else s[idx] = '0';
	}
	for(int i = n-2; i>=2; i--) if(s[i] == '?') {
		if(ex) s[i] = '1', ex--;
		else s[i] = '0';
	}

	ll cur = 1;
	c = oc;
	for(int i = 0; i<n-1; i++) {
		if(s[i] == '1') {
			cur *= 2;
			if(c % 2 == 0) c /= 2;
		} else {
			c /= __gcd(i, c);
			cur *= i;
		}
		cur = cur % mod;
		if(c == 1) break;
	}

	cout << (cur == 0 || c == 1 ? -1 : cur) << "\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while(t--) solve();
}

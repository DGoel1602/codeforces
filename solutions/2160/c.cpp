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
	bitset<31> bs(n);
	string s = bs.to_string();

	while(s.size() && s.back() == '0') s.pop_back();
	reverse(all(s));
	while(s.size() && s.back() == '0') s.pop_back();

	string cp(s);
	reverse(all(s));

	cout << (cp == s && (s.size() % 2 == 0 || s[s.size()/2] == '0') ? "YES\n" : "NO\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

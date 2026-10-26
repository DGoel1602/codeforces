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
	string s, t; cin >> s >> t;
	int cnt = 0;
	for(char c: s) cnt ^= c == 'f';
	for(char c: t) cnt ^= c == 'f';
	cout << cnt << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

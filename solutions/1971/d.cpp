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
	string s; cin >> s;
	int gs = 0;
	rep(i, 0, sz(s))
		if(i == 0 || s[i] != s[i-1]) gs++;
	bool is = 0;
	for(int i = 0; i<(sz(s)-1); i++) if(s[i] == '0' && s[i+1] == '1') is = 1;
	cout << gs - is << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

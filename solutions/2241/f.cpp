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
	int n; cin >> n;
	string s; cin >> s;
	int c1 = 0, invs = 0;

	rep(i, 0, n) {
		if(s[i] == '0') invs += c1;
		else c1++;
	}

	if(invs % 2) return void(cout << "Alice\n");

	int no = 0, nz = 0;
	for(int i = 0; i<n; i++) {
		no += s[i] == '1';
		if(s[i] == '0' && no % 2) return void(cout << "Alice\n");
	}
	for(int i = n-1; i>=0; i--) {
		nz += s[i] == '0';
		if(s[i] == '1' && nz % 2) return void(cout << "Alice\n");
	}
	cout << "Bob\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

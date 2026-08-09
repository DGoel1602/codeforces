#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()
const ll mod = 998244353;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	vector<int> det(2, -1);
	for(int i = 0; i<n; i++) if(s[i] != '?') {
		int t = i & 1;
		int cur = (s[i] - '0') ^ ((i / 2) & 1);
		if(det[t] == -1) det[t] = cur;
		else if(det[t] != cur) return void(cout << "0\n");
	}
	int res = 1;
	for(int i = 0; i<2; i++) if(det[i] == -1) res <<= 1;
	cout << res << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

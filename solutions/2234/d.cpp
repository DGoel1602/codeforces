#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

string x(string a, string b){
	string res(a);
	for(int i = 0; i<a.size(); i++) res[i] = (a[i] == b[i] ? '0' : '1');
	return res;
}

int cnt(string a) {
	int res = 0;
	for(char c: a) res += c == '1';
	return res;
}

void solve() {
	int n, k; cin >> n >> k;
	string o, ko; cin >> o >> ko;
	int els = (1 << k) + 1;
	int as = (els+2) / 3, bs = (els+2) / 3, cs = els / 3;
	string xo = x(o, ko);
	int res = (cnt(xo) * (n - cnt(xo))) * cs
						+ (cnt(o) * (n - cnt(o))) * as
						+ (cnt(ko) * (n - cnt(ko))) * bs;
	cout << res << "\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

// a c b a c b a c b
// a b c a b c a b c a b c a b c a b
// a b c a b
// a c b a c b a c b 0 0 0 0 0 0 0 c 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 b

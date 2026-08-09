#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n, k; cin >> n >> k;
	n *= 2;
	string s; cin >> s;
	string t(s);
	for(int i = 0; i<n; i++) {
		if(s[(i+1)%n] == '0' && s[i] == '1') swap(t[i], t[(i+1)%n]);
	}
	vector<int> res(2);
	rep(i, 0, n) res[i%2] += t[i] - '0';
	cout << res[1] << " " << res[0] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

// 011101
// 10011110101011
// 01011101010111

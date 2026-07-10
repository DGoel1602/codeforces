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
	int n, x; cin >> n >> x;
	string s; cin >> s;
	x--;
	int l = -1, r = n;
	for(int i = x; i>=0; i--)
		if(s[i] == '#') {
			l = i;
			break;
		}
	for(int i = x; i<n; i++)
		if(s[i] == '#') {
			r = i;
			break;
		}
	int opt1 = min(x + 1, n - r + 1);
	int opt2 = min(n - x, l + 1 + 1);
	cout << max(opt1, opt2) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

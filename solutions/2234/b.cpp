#include <bits/stdc++.h>
#include <string>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	string s = to_string(n);
	if(s.size() == 1 || n == 11) return void(cout << n << " 0" << "\n");
	int cur = n % 12;
	while(cur <= n) {
		string as = to_string(cur), as2 = to_string(cur);
		reverse(all(as2));
		if(as == as2) {
			cout << as << " " << n - cur << "\n";
			return;
		}
		cur += 12;
	}
	cout << "-1\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

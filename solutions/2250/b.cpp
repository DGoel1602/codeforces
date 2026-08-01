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
	int n, k; cin >> n >> k;
	int o = n/2, z = (n+1)/2;
	int mx = n - 2;
	int left = mx - k;
	if(left < 0) return void(cout << "-1\n");
	int tw = left / 2, ex = left % 2;
	if(ex) cout << "0", z--;
	for(int i = 0; i<(o-tw); i++) cout << "1";
	for(int i = 0; i<tw; i++) cout << "01", z--;
	for(int i = 0; i<z; i++) cout << "0";
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

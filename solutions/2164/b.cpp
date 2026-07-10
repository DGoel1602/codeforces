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
	vi a(n);
	for(int &x: a) cin >> x;
	rep(i, 0, n)
		rep(j, i+1, n)
			if((a[j] % a[i]) % 2 == 0) return void(cout << a[i] << " " << a[j] << "\n");
	cout << -1 << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

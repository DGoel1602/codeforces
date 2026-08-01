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
	int n, k, m; cin >> n >> k >> m;
	if(m < k) return void(cout << "NO\n");
	vi a(n, 1);
	a[k-1] = (m - (k - 1));
	cout << "YES\n";
	for(int x: a) cout << x << ' ';
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

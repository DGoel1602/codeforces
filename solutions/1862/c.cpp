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
	vi res(n, -1);
	int cur = 0;
	int ls = 0;
	for(int i = n-1; i>=0; i--) {
		if(a[i] > n) return void(cout << "NO\n");
		int g = cur + a[i] - ls;
		for(; cur<g; cur++) {
			if(cur >= n) return void(cout << "NO\n");
			res[cur] = i + 1;
		}
		ls = a[i];
	}
	rep(i, 0, n) if(res[i] != a[i]) return void(cout << "NO\n");
	cout << "YES\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

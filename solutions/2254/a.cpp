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
	vi a(3);
	for(int &x: a) cin >> x;
	int cnt = 0;
	sort(all(a));
	while(a[0] != a[1] && a[1] != a[2]) {
		sort(all(a));
		cnt++;
		a[2]--;
		a[0]++;
		sort(all(a));
	}
	cout << cnt << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

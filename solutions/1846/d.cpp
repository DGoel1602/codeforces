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
	int n, d, h; cin >> n >> d >> h;
	vi a(n);
	for(int &x: a) cin >> x;
	double res = 0;
	sort(all(a));
	rep(i, 0, n) {
		if(i < n - 1 && a[i+1] < a[i] + h) {
			int diff = a[i+1]-a[i];
			double delta = ((double)d / 2) / h;
			double top = d - 2 * delta * diff;
			res += top * diff + 0.5 * (2 * delta * diff) * diff;
		} else {
			res += 0.5 * d * h;
		}
	}
	cout << fixed << setprecision(10) << res << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

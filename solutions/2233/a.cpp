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
	int n, x, y, z; cin >> n >> x >> y >> z;
	int done = x * z;
	int hours = z;
	while(done < n) {
		done += x + 10 * y;
		hours++;
	}
	cout << min((n + x + y - 1) / (x + y), hours) << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

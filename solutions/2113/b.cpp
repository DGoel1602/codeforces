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
	int w, h, a, b; cin >> w >> h >> a >> b;
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

	if(x1 != x2 && (x2 - x1) % a == 0) return void(cout << "Yes\n");
	if(y1 != y2 && (y2 - y1) % b == 0) return void(cout << "Yes\n");
	cout << "No\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

// 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 1 1 1 0 0 0
// 0 0 0 0 1 1 1 0 0 0
// 0 0 0 0 0 0 0 0 0 0
// 1 1 1 0 0 0 0 0 0 0
// 1 1 1 0 0 0 0 0 0 0


// 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 1 1 1 0
// 0 0 0 0 0 0 1 1 1 0
// 0 0 0 0 0 0 0 0 0 0
// 1 1 1 0 0 0 0 0 0 0
// 1 1 1 0 0 0 0 0 0 0

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i<b; ++i)

void solve() {
	int n; cin >> n;
	vvi res(2, vi(2, 0));
	res[0][0] = 1;

	int par = 1;
	int cs = 1;
	int cur = 1;

	n--;
	while(n > 0) {
		int total = min(cur + 1 + cur + 2, n);
		for(int i = 0; i<total; i++) {
			res[par][cs]++;
			cs ^= 1;
			n--;
		}
		cur = cur + 2;
		par ^= 1;
	}
	cout << res[0][0] << " " << res[0][1] << " " << res[1][0] << " " << res[1][1] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

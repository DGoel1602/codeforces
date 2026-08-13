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
	int n, q; cin >> n >> q;
	vi res(51, -1);
	rep(i, 0, n) {
		int x; cin >> x;
		if(res[x] == -1) res[x] = i;
	}
	while(q--) {
		int x; cin >> x;
		rep(i, 0, 51) if(res[i] < res[x]) res[i]++;
		cout << res[x] + 1 << " ";
		res[x] = 0;
	}
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while(t--) solve();
}

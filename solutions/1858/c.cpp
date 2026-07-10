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
	vi res(n);
	res[0] = 1;
	int cur = 1;

	set<int> avail;
	for(int i = 2; i<=n; i++) avail.insert(i);
	int i;
	for(i = 2; i <= n; i++) {
		if(cur >= n || !avail.count(i)) continue;
		int add = i;
		while(add <= n) {
			res[cur] = add;
			avail.erase(add);
			cur++;
			add *= 2;
		}
	}
	for(int x: res) cout << x << " ";
	cout << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n, m; cin >> n >> m;
	vi cnt(n);
	rep(i, 0, m) {
		int u, v; cin >> u >> v;
		--u; --v;
		cnt[u]++;
		cnt[v]++;
	}
	sort(all(cnt));

	map<int, int> freq;
	for(int x: cnt) freq[x]++;
	int mn = *min_element(all(cnt)), mx = *max_element(all(cnt));

	if(freq[1] == 2 && freq[2] == n - 2 && mn == 1 && mx == 2 && m == n - 1)
		return void(cout << "bus topology\n");
	if(freq[2] == n && mn == 2 && mx == 2 && m == n)
		return void(cout << "ring topology\n");
	if(freq[n-1] == 1 && freq[1] == n-1 && mn == 1 && mx == n-1 && m == n-1)
		return void(cout << "star topology\n");
	cout << "unknown topology\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while(t--) solve();
}

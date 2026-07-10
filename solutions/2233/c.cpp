#include <bits/stdc++.h>
#include <queue>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vi rem(n);
	for(int iter = 0; iter<k; iter++) {
		priority_queue<pair<int, int>> pq;
		int cur = 0;
		rep(i, 0, n) if(!rem[i]) {
			if(s[i] == '(') cur++;
			else pq.push({cur, i}), cur = max(cur-1, 0);
		}
		cur = 0;
		for(int i = n-1; i>=0; i--) if(!rem[i]) {
			if(s[i] == '(') pq.push({cur, i}), cur = max(cur-1, 0);
			else cur++;
		}
		auto [_, idx] = pq.top();
		rem[idx] = 1;
	}
	for(int x: rem) cout << x;
	cout << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

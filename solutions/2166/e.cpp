#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define int long long

void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	vector<int> qs(q);
	for(int &x: a) cin >> x;
	for(int &x: qs) cin >> x;

	sort(a.begin(), a.end(), greater<>());
	while(a.size() > 31) a.pop_back();

	for(int q: qs) {
		vector<int> bits;
		priority_queue<int> pq;
		for(int x: a) pq.push(x);
		for(int j = 31; j>=0; j--) if(q & (1 << j)) bits.push_back(j);
		int res = 0;
		for(int b: bits) {
			int t = pq.top(); pq.pop();
			if((1 << b) > t) res += (1 << b) - t, pq.push(0);
			else if(b == 31 - __builtin_clz(t)) pq.push(t - (1 << b));
			else break;
		}
		cout << res << '\n';
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

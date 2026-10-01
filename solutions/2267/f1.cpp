#include <bits/stdc++.h>
using namespace std;

vector<int> op(vector<int> &a) {
	vector<int> b;
	for(int i = 0; i<a.size(); i++) {
		for(int j = i+1; j<a.size(); j++) b.push_back(a[i] ^ a[j]);
	}
	sort(b.begin(), b.end());
	return b;
}

void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	sort(a.begin(), a.end());

	vector<int> res(q);
	vector<pair<int, int>> queries(q);
	for(int i = 0; i<q; i++) cin >> queries[i].first, queries[i].second = i;
	sort(queries.begin(), queries.end());

	int cur = 0, mx = a.back() - a[0];
	for(auto [q, idx]: queries) {
		while(mx && cur < q) {
			vector<int> b = op(a);
			for(int i = 0; i<n; i++) a[i] = b[i];
			mx = a.back() - a[0];
			cur++;
		}
		res[idx] = mx;
	}
	
	for(int x: res) cout << x << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

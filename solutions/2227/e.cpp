#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	stack<int> ms;
	vector<int> ls(n, -1);
	for(int i = 0; i<n; i++) {
		while(ms.size() && a[ms.top()] >= a[i]) ms.pop();
		if(ms.size()) ls[i] = ms.top();
		ms.push(i);
	}
	while(ms.size()) ms.pop();

	int mi = 1e9;
	int def = 0, b = 0;
	for(int i = n-1; i>=0; i--) {
		int extra = max(0LL, a[i] - mi);
		def += extra;

		int due = -(extra > 0);
		while(ms.size() && a[ms.top()] >= a[i]) ms.pop();
		if(!ms.size()) due += i - ls[i];
		ms.push(i);
		b = max(b, due);
		mi = min(mi, a[i]);
	}
	b = max(b + def, def);
	cout << b - 1 << "\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	ll k = 0;
	for (int i = 0; i < n-1; i++)
		if (a[i] > a[i+1]) k = max(k, a[i] - a[i+1]);

	vector<int> state(n, -1);
	state[0] = 0;

	for (int i = 0; i < n-1; i++) {
		for (int xi = 0; xi < 2; xi++) {
			if (state[i] != -1 && state[i] != xi) continue;
			for (int xj = 0; xj <= 1; xj++) {
				ll l = a[i] + xi * k, r = a[i+1] + xj * k;
				if (l <= r) {
					if (state[i+1] == -1) state[i+1] = xj;
					else state[i+1] = state[i+1];
				}
			}
		}
		if (state[i+1] == -1) return void(cout << "NO\n");
	}
	cout << "YES\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) solve();
}

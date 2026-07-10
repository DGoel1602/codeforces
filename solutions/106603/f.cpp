#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<pair<int, ll>> a(n);
	for(auto &[a, b]: a) cin >> a >> b;
	sort(a.begin(), a.end());
	vector<ll> dp2(n+1);
	for(int j = 0; j<min(20, n); j++) {
		auto [s, v] = a[j];
		for(int i = s; i<=n; i++) dp2[i] = max(dp2[i], dp2[i-s] + v);
	}
	for(int i = 1; i<=n; i++) cout << dp2[i] << " ";
	cout << '\n';
}

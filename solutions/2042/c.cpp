#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;

	vector<int> suf(n);
	suf[n-1] = (s[n-1] == '1' ? 1 : -1);
	for(int i = n-2; i>=1; i--) suf[i] = suf[i+1] + (s[i] == '1' ? 1 : -1);
	sort(suf.begin(), suf.end(), greater<>());

	long long cur = 0;
	for(int i = 0; i<n; i++) {
		cur += (long long)suf[i];
		if(cur >= k) return void(cout << i + 2 << '\n');
	}
	cout << -1 << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

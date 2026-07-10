#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;

	vector<int> left(n, 1), right(n, 1);
	for(int i = 1; i<n; i++)
		if(a[i-1] < a[i]) left[i] += left[i-1];

	for(int i = n-2; i>=0; i--)
		if(a[i+1] < a[i]) right[i] += right[i+1];

	vector<int> ma(n);
	for(int i = 0; i<n; i++) ma[i] = max(left[i], right[i]);
	int mx = 0;
	map<int, int> freq;
	for(int x: ma) freq[x]++, mx = max(mx, x);

	if(freq[mx] > 1 || mx % 2 == 0) {
		cout << "0\n";
		return 0;
	}

	for(int i = 0; i<n; i++) {
		if(ma[i] == mx) cout << (left[i] == right[i]) << '\n';
	}
}

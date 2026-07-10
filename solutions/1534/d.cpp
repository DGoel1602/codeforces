#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	cout << "? 1" << endl;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	vector<int> freq(2);
	for(int x: a) freq[x%2]++;
	int q = 0;
	if(freq[0] > freq[1]) q = 1;
	vector<pair<int, int>> res;
	if(!q)
		for(int i = 0; i<n; i++) if(a[i] == 1) res.push_back({0, i});
	for(int i = 1; i<n; i++) if(a[i] % 2 == q) {
		vector<int> b(n);
		cout << "? " << i + 1 << endl;
		for(int &x: b) cin >> x;
		for(int j = 0; j<n; j++) if(b[j] == 1) res.push_back({i, j});
	}
	cout << "!" << endl;
	for(auto [a, b]: res) cout << a + 1 << " " << b + 1 << endl;
}

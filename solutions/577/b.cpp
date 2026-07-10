#include <bits/stdc++.h>
using namespace std;

#define SZ 2000

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<int> a(n);
	bool works = false;

	for(int i = 0; i<n; i++) {
		int x; cin >> x;
		x %= m;
		a[i] = x;
	}
	bitset<SZ> bs = 0;
	bitset<SZ> mask = 0;
	for(int i = 0; i<m; i++) mask[i] = 1;

	bs[0] = 1;
	for(int x: a) {
		bitset<SZ> ns = bs << x;
		ns |= (ns >> m);
		//cout << ns << " ";
		ns &= mask;
		if(ns[0]) works = true;
		bs |= ns;
		//cout << bs << "\n";
	}
	cout << (works ? "YES" : "NO") << "\n";
}

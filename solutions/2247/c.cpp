#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
	int n; cin >> n;
	vi a(n), b(n);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;
	int zo = 0, oz = 0, zz = 0, oo = 0;
	rep(i, 0, n) {
		if(a[i] == 0 && b[i] == 1) zo++;
		if(a[i] == 1 && b[i] == 0) oz++;
		if(a[i] == 0 && b[i] == 0) zz++;
		if(a[i] == 1 && b[i] == 1) oo++;
	}
	if(!zo && !oz) return void(cout << "0\n");
	if(oz == 0) {
		if(oo && zz) return void(cout << "2\n");
		return void(cout << "-1\n");
	}
	if(oz % 2) return void(cout << "1\n");
	cout << "2\n";
}

// 1 1 0 1 1 1
// 1 1 1 1 1 1

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

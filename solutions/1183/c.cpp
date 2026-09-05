#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i<b; ++i)

void solve() {
	int k, n, a, b; cin >> k >> n >> a >> b;
	int lo = 0, hi = n;
	if((k-1) / b < n) return void(cout << "-1\n");
	while(lo != hi) {
		int m = lo + (hi - lo + 1) / 2;
		int ot = n - m;
		int nk = k - b * ot;
		if(ot + (nk - 1) / a < n) hi = m - 1;
		else lo = m;
	}
	cout << lo << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

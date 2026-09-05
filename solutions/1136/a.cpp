#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i<b; ++i)

void solve() {
	int n; cin >> n;
	vector<pii> a(n);
	for(auto &[c, b]: a) cin >> c >> b;
	int k; cin >> k;
	for(int i = 0; i<n; i++) {
		if(k == a[i].second + 1) return void(cout << n - i - 1 << '\n');
		if(k <= a[i].second) return void(cout << n - i << '\n');
	}
	cout << 0 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while(t--) solve();
}

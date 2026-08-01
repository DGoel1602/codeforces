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
	vi a(n);
	for(int &x: a) cin >> x;
	vi cp(a);
	pii mnmx = {0, 1e9};
	for(int i = 0; i<n; i+=2) {
		if(i == n - 1) return void(cout << "NO\n");
		int on = a[i], tw = a[i+1];
		if(on == tw) return void(cout << "NO\n");
		mnmx.first = max(mnmx.first, tw+1);
		mnmx.second = min(mnmx.second, on-1);
	}
	cout << (mnmx.second >= mnmx.first ? "YES\n" : "NO\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

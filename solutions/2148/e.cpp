#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n, k; cin >> n >> k;
	vi a(n); 
	for(int &x: a) cin >> x;
	vi freq(n+1);
	for(int x: a) freq[x]++;
	vi ma(n+1);
	for(int i = 1; i<=n; i++) {
		if(freq[i] % k != 0) return void(cout << "0\n");
		ma[i] = freq[i]/k;
	}
	ll l = -1;
	freq = vi(n+1, 0);
	ll res = 0;
	for(ll r = 0; r<n; r++) {
		freq[a[r]]++;
		while(freq[a[r]] > ma[a[r]]) {
			l++;
			freq[a[l]]--;
		}
		res += r - l;
	}
	cout << res << "\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

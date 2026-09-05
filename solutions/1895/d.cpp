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
	vi a(n-1);
	for(int &x: a) cin >> x;
	for(int i = 1; i<(n-1); i++) a[i] ^= a[i-1];
	int res = 0;
	vi act(31);
	for(int i = 0; i<31; i++) 
		for(int j = 0; j<n; j++) if(j & (1 << i)) act[i]++;
	vi got(31);
	for(int i = 0; i<31; i++) 
		for(int x: a) if(x & (1 << i)) got[i]++;
	for(int i = 0; i<31; i++) if(act[i] != got[i]) res |= (1 << i);
	cout << res << " ";
	for(int x: a) cout << (res ^ x) << " ";
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while(t--) solve();
}

// 1 7 6 2 3

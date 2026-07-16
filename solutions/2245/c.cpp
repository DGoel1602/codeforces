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
	int n, k; cin >> n >> k;
	k ^= n;

	int o = 31 - __builtin_clz(n-1);
	if(n-1 == 0) o = -1;
	int ot = 31 - __builtin_clz(k);
	if(k == 0) ot = -1;

	if(o < ot) return void(cout << "NO\n");
	cout << "YES\n";
	vector<int> using_at_end(n);
	for(int i = 0; i<30 && (1 << i) < n; i++) if(k & (1 << i)) using_at_end[(1 << i)] = 1;
	for(int i = 1; i<=(n-1); i++) if(!using_at_end[i]) cout << i << " ";
	cout << 0 << " ";
	for(int i = 0; i<=(n-1); i++) if(using_at_end[i]) cout << i << " ";
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

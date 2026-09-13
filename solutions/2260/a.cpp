#include <bits/stdc++.h>
#include <numeric>
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
	if(accumulate(all(a), 0LL) > n - 2) return void(cout << "-1\n");
	int res = (a[0] != 0) + (a.back() != 0);
	cout << res << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

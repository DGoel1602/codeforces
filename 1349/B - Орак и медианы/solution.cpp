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
	vi a(n);
	bool has = false;
	for(int &x: a) cin >> x, has |= x == k;
	if(!has) return void(cout << "no
");
	rep(i, 0, n) {
		if(a[i] >= k) {
			if(i > 0 && a[i-1] >= k) return void(cout << "yes
");
			if(i > 1 && a[i-2] >= k) return void(cout << "yes
");
		}
	}
	if(n == 1 && a[0] == k) return void(cout << "yes
");
	cout << "no
";
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
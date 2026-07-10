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
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	if(a.size() == 1) return void(cout << (a[0] == 0 ? "No\n" : "Yes\n"));
	if(a.size() > 2) return void(cout << "No\n");
	if(a[0] != -1) return void(cout << "No\n");
	if(a[1] == 0) return void(cout << "No\n");
	cout << "Yes\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

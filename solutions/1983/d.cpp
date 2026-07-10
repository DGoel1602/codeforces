#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

void solve() {
	int n; cin >> n;
	vi a(n), b(n);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;
	int inv = 0, inv2 = 0;
	Tree<pair<int, int>> t1, t2;
	for(int i = 0; i<n; i++) {
		auto it = t1.upper_bound({a[i], 1e9});
		if(it != t1.end()) inv += i - t1.order_of_key(*it);
		t1.insert({a[i], i});
	}
	for(int i = 0; i<n; i++) {
		auto it = t2.upper_bound({b[i], 1e9});
		if(it != t2.end()) inv += i - t2.order_of_key(*it);
		t2.insert({b[i], i});
	}
	sort(all(a)); sort(all(b));
	cout << ((inv % 2 != inv2 % 2 || a != b) ? "NO\n" : "YES\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

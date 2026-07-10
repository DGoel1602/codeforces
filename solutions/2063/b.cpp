#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

int qu(vector<int> &a, vector<int> &b) {
	int i;
	for(i = 0; i<min(a.size(), b.size()); i++) {
		if(a[i] <= b[(int)b.size()-i-1]) continue;
		break;
	}
	int sum = 0;
	for(int j = 0; j<i; j++) sum += a[j];
	for(int j = 0; j<=((int)b.size()-i-1); j++) sum += b[j];
	return sum;
}

void solve() {
	int n, l, r; cin >> n >> l >> r;
	--l;
	vi d, b, c1, c2;
	vi a(n);
	for(int &x: a) cin >> x;
	for(int i = 0; i<l; i++) b.push_back(a[i]);
	for(int i = l; i<r; i++) c1.push_back(a[i]), c2.push_back(a[i]);
	for(int i = r; i<n; i++) d.push_back(a[i]);
	sort(all(b));
	sort(all(c1));
	sort(all(c2));
	sort(all(d));
	cout << min(qu(b, c1), qu(d, c2)) << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

int query(vi &idxs) {
		cout << "? " << idxs.size() << " ";
		for(int idx: idxs) cout << idx << " ";
		cout << endl;
		int r; cin >> r;
		return r;
}

void solve() {
	int n; cin >> n;
	n *= 2;
	vi a(n, 0), idxs;
	for(int i = 0; i<n; i++) {
		idxs.push_back(i+1);
		a[i] = query(idxs);
		if(a[i]) idxs.pop_back();
	}
	idxs.clear();
	for(int i = n-1; i>=0; i--) {
		idxs.push_back(i+1);
		if(a[i]) continue;
		a[i] = query(idxs);
		idxs.pop_back();
	}
	cout << "! ";
	for(int x: a) cout << x << " ";
	cout << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

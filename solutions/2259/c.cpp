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

	int cnt = 0;
	for(int x: a) cnt += x == 1 || x == -1;
	if(cnt < 2) {
		for(int x: a) cout << (x == -1 ? 1 : x) << " ";
		cout << '\n';
		return;
	}

	int fno = n;
	for(int i = n-1; i>=0; i--) if(a[i] == -1) fno = i;
	int bl = -1, br = -1;

	auto tr = [&](int i, int j) {
		if(i == -1 || j == -1 || i == n || j == n) return;
		int dist = br - bl + 1;
		if(j - i + 1 > dist) bl = i, br = j;
	};

	int lo = -1;
	rep(i, 0, n) if(a[i] != 0) {
		int earl = lo == -1 ? fno : lo;
		tr(earl, i);
		if(a[i] == 1) lo = i;
	}

	rep(i, 0, n) {
		if(i == bl || i == br) cout << 1 << " ";
		else if(a[i] == -1) cout << "0 ";
		else cout << a[i] << " ";
	}
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

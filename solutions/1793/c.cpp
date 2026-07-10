#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;
	int l = 0, r = n-1;

	int low = 1, high = n;
	auto works = [&](int i) {
		if(a[i] == low) {
			low++;
			return false;
		}
		if(a[i] == high) {
			high--;
			return false;
		}
		return true;
	};

	while(l <= r) {
		if(!works(l)) l++;
		else if(!works(r)) r--;
		else return void(cout << l + 1 << " " << r + 1 << "\n");
	}
	cout << "-1\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

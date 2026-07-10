#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t; cin >> t;
	rep(_, 0, t) {
		int n; cin >> n;
		vi init(n);
		for(int &x: init) cin >> x;

		rep(i, 0, n) {
			cout << n + 1 - init[i] << " ";
		}

		cout << "\n";

	}
}

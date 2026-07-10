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
	while(t--) {
		ll a, b; cin >> a >> b;
		bool a_odd = a % 2 == 1;
		bool b_odd = b % 2 == 1;
		if(a_odd && b_odd) {
			cout << a * b + 1 << "\n";
		} else if (!a_odd && !b_odd) {
			cout << (a * b / 2) + 2 << "\n";
		} else if (!a_odd) {
			cout << -1 << "\n";
		} else {
			ll k = b / 2;
			if(k % 2 == 0) {
				cout << a * k + 2 << "\n";
			} else {
				cout << -1 << "\n";
			}
		}
	}
}

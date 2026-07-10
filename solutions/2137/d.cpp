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
		int n; cin >> n;
		vi init(n);
		for(int &x: init) cin >> x;
		vi freq(n + 1, 0);
		rep(i, 0, n) {
			freq[init[i]]++;
		}

		map<int, pair<int, int>> mapping;
		int cur = 1;

		bool returned = false;
		rep(i, 1, n + 1) {
			if(freq[i] % i != 0) {
				cout << -1 << "\n";
				returned = true;
				break;
			} else {
				mapping[i] = {cur, freq[i] / i};
				cur += freq[i] / i;
			}
		}

		if(returned) continue;
		
		map<int, int> cur_used;

		rep(i, 0, n) {
			pii sc = mapping[init[i]];
			cout << sc.first + cur_used[init[i]] / init[i] << " ";
			cur_used[init[i]]++;
		}
		cout << "\n";
	}
}

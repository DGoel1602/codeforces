#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int mex(int n, vi &found) {
	rep(i, 0, n + 1) {
		if(!found[i]) return i;
	}
	return -1;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vi init(n);
		for(int &x: init) cin >> x;

		vi found(n + 1, 0);	
		for(int x: init) found[x]++;

		int m = mex(n, found);
		ll s1 = 0;
		rep(i, 0, n) {
			if(found[init[i]] == 1) {
				init[i] = min(init[i], m);
			} else {
				init[i] = m;
			}
			s1 += init[i];
		}

		found.assign(n + 1, 0);
		for(int x: init) found[x]++;

		m = mex(n, found);
		ll s2 = 0;
		rep(i, 0, n) {
			if(found[init[i]] == 1) {
				init[i] = min(init[i], m);
			} else {
				init[i] = m;
			}
			s2 += init[i];
		}

		found.assign(n + 1, 0);
		for(int x: init) found[x]++;

		m = mex(n, found);
		ll s3 = 0;
		rep(i, 0, n) {
			if(found[init[i]] == 1) {
				init[i] = min(init[i], m);
			} else {
				init[i] = m;
			}
			s3 += init[i];
		}
		
		ll ret = s1;
		if(k > 1) {
			if(k % 2 == 0) ret = s2;
			else ret = s3;
		}

		cout << ret << endl;
	}
}

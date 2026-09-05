#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
	int n, m; cin >> n >> m;
	vi a(n);
	for(int &x: a) cin >> x;
	sort(all(a));

	vi freq(2*m+1);
	for(int x: a) freq[x]++;
	vi suf(2*m+2);
	for(int i = 2*m; i>=0; i--) suf[i] = suf[i+1] + freq[i];

	vi mx(m+1);
	for(int tar = 1; tar <= m; tar++) {
		int cur = 0;
		for(int j = 1; j * tar <= m; j++) {
			int p = j + 1;
			cur += suf[j*tar];
			
			if(__builtin_popcount(p) == 1) {
				int k = __lg(p);
				mx[k] = max(mx[k], cur + (p * tar <= m ? freq[p * tar] : 0));
			}
		}
	}

	int amx = a.back();
	int cur = 0;
	while(amx > 1) amx = (amx + 1)/2, cur++;

	int sum = accumulate(all(a), 0LL);
	rep(i, 1, m+1) {
		if(i >= cur) cout << sum << " ";
		else cout << mx[i] << " ";
	}
	cout << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
